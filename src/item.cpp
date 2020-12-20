#include <voidworks/item.h>

ItemCategory GetItemCategoryById(uint32_t id)
{
  switch (id)
  {
    case 0x00000000 ... 0x00000000:
      return ItemCategory::Ammunition;
    case 0x00000000 ... 0x00000000:
      return ItemCategory::Weapon;
    case 0x00000000 ... 0x00000000:
      return ItemCategory::Armor;
    case 0x00000000 ... 0x00000000:
      return ItemCategory::Accessory;
    case 0x00000000 ... 0x00000000:
      return ItemCategory::Goods;
    default:
      return ItemCategory::Invalid;
  }
}

std::string GetItemNameById(uint32_t id)
{
  for (auto item : GetItemList())
  {
    if (item.second == id)
    {
      return item.first;
    }
  }
  return "Unknown item";
}

uint8_t GetMaxReinforcementLevel()
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  return ds3->ReadByte(
      ds3->GetDynamicAddress({BASE_A, 0x00, 0x00})
    );
}

void ItemSpawn(uint32_t id, uint32_t infusion, uint32_t level, uint32_t quantity, uint32_t durability)
{
  void (*sprjItemSpawn)(...);
  uintptr_t process_base_address_ = ProcessInterface::GetInstance()->GetBaseAddress();
  *(uintptr_t*)&sprjItemSpawn = process_base_address_ + FUNC_ITEM_SPAWN;
  uintptr_t sprjItemMapManager = *(uintptr_t*)(process_base_address_ + SPRJ_MAP_ITEM_MANAGER);
  uint8_t item_data[64] = {0};
  uint32_t counter = 0x00;
  id += level + infusion;
  uint32_t call_quantity = 1;
  uint32_t goods_quantity = quantity;
  ItemCategory category = GetItemCategoryById(id);
  switch (category)
  {
    case ItemCategory::Ammunition:
    case ItemCategory::Goods:
    {
      break;
    }
    default:
    {
      call_quantity = quantity;
      goods_quantity = 1;
      break;
    }
  }
  memcpy((item_data+0x00), &counter, 4);
  memcpy((item_data+0x00), &id, 4);
  memcpy((item_data+0x00), &goods_quantity, 4);
  memcpy((item_data+0x00), &durability, 4);
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG
      "Spawning item %#x, infusion %d, "
      "level %d, quantity %d, durability %d\n"
      ANSI_RESET,
      id, infusion, level, quantity, durability
    );
#endif
  for (uint32_t i = 0; i < call_quantity; i++)
  {
    sprjItemSpawn(sprjItemMapManager, (item_data+0x00), item_data);
  }
}

void DisableItemUpgradeCost()
{
  auto no_item_upgrade_cost = new EquipMtrlSetParam();
  no_item_upgrade_cost->PatchAll4Byte(0x00, -1);
  no_item_upgrade_cost->PatchAllByte(0x00, 255);
#if (DEBUG >= LOG_WARNING)
  printf("Item upgrade cost temporarily removed\n");
#endif
}
