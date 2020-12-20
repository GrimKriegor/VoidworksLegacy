#ifndef WORLD_H_
#define WORLD_H_

#include <voidworks/common.h>
#include <voidworks/position.h>
#include <voidworks/process.h>
#include <voidworks/session.h>

#define MOB_KILL_LIST_SIZE 104

enum class EntityId : uint32_t;
enum class OnlineAreaId : uint32_t;
bool IsValidEntityPtr(mLvPtr);
void KillMobs();
void* FindEntityPointer(uint32_t);
void* FindEntityPointer(EntityId);

class EntityInterface
{
  private:
    uint16_t forward_id_ = 0;
    void* base_pointer_ = NULL;
    ProcessInterface* ds3_ = NULL;
    EntityInterface();
  public:
    EntityInterface(uint16_t);
    EntityInterface(EntityId);
    EntityInterface(void*);
    ~EntityInterface();
    uint32_t GetForwardId();
    void* GetPointer();
    bool IsLoaded();
    void SetHealth(uint32_t);
    void SetPosition(Pos);
    void SetNoDead(bool);
    void SetGravity(bool);
};

enum class EntityId : uint32_t
{
  DemonFromBelow = 0x0000,
  DemonInPain    = 0x0000,
  Midir          = 0x0000,
};

enum class OnlineAreaId : uint32_t
{
    // Cemetery of Ash
    Cemetary_of_Ash_Iudex_Gundyr                = 400100,
    Cemetary_of_Ash                             = 400101,
    Firelink_Shrine                             = 400102,
    // High Wall of Lothric
    High_Wall_of_Lothric                        = 300001,
    Darkwraith_Chanmber                         = 300002,
    Bonfire2                                    = 300003,
    Lower_High_Wall                             = 300004,
    Dancer_of_Boreal_Valley                     = 300006,
    Vordt_of_Boreal_Valley                      = 300007,
    Post_Dancer                                 = 300008,
    Post_Vordt                                  = 300009,
    //King's Garden
    Kings_Garden_Main_Area                      = 300021,
    Kings_Garden_Lift_Shortcut_PreOceiros       = 300022,
    Kings_Garden_Oceiros,_the_Consumed_King     = 300023,
    Kings_Garden_PostOceiros                    = 300024,
    //Lothric Castle
    Lothric_Castle                              = 301000,
    Lothric_Castle_Dragon_Barracks              = 301001,
    Lothric_Castle_Lower_Barracks               = 301002,
    Lothric_Castle_Altar_of_Sunlight            = 301003,
    Lothric_Castle_Dragonslayer_Armor           = 301010,
    //Undead Settlement
    Undead_Settlement_Foot_of_the_High_Wall     = 310000,
    Undead_Settlement_Dilapidated_Bridge        = 310001,
    Undead_Settlement_Cliff_Underside           = 310002,
    Undead_Settlement_Irina                     = 310003,
    Undead_Settlement_Curserotted_Greatwood     = 310020,
    Undead_Settlement_Before_Road_of_Sacrifices = 310021,
    //Archdragon Peak
    Archdragon_Peak_Nameless_King_Boss          = 320000,
    Archdragon_Peak                             = 320001,
    Archdragon_Peak_Ancient_Wyvern              = 320002,
    Archdragon_Peak_Dragonkin_Mausoleum         = 320010,
    Archdragon_Peak_Nameless_King_Bonfire       = 320011,
    Archdragon_Peak_Second_Wyvern               = 320012,
    Archdragon_Peak_Great_Belfry                = 320013,
    Archdragon_Peak_Mausoleum_Lift              = 320020,
    //Road of Sacrifices
    Crucifixion_Woods_Crystal_Sage              = 330000,
    Crucifixion_Woods_Halfway_fortress          = 330001,
    Crucifixion_Woods_Road_of_Sacrifices        = 330020,
    Crucifixion_Woods_After_Crystal_Sage        = 330021,
    //Faron Keep
    Farron_Keep_Abyss_Watchers                  = 330010,
    Farron_Keep_Keep_Ruins                      = 330011,
    Farron_Keep_Swamp                           = 330012,
    Farron_Keep_Old_Wolf_of_Farron              = 330015,
    Farron_Keep_PreAbyss_Watchers               = 330013,
    Farron_Keep_Perimeter                       = 330014,
    //The Grand Archives
    Grand_Archives                              = 341000,
    Grand_Archives_Archive_Rooftops             = 341001,
    Grand_Archives_PostTrio                     = 341002,
    Grand_Archives_Grand_Rooftop                = 341003,
    Grand_Archives_Twin_Princes                 = 341010,
    //Cathedral
    Cathedral_Cleansing_Chapel                  = 350001,
    Cathedral_Below_Chapel                      = 350002,
    Cathedral_Outside_Cathedral_Door            = 350003,
    Cathedral_of_the_Deep                       = 350004,
    Cathedral_PreDeacons                        = 350005,
    Cathedral_Deacons_of_the_Deep               = 350000,
    Cathedral_Rosaria                           = 350010,
    Cathedral_PreRosaria                        = 350011,
    Cathedral_PreCleansing_Chapel               = 350020,
    //Irithyll of Boreal
    Irithyll_of_the_Boreal_Valley               = 370000,
    Irithyll_Central_Irithyll                   = 370001,
    Irithyll_Church_of_Yorshka                  = 370002,
    Irithyll_Distant_Manor                      = 370003,
    Irithyll_Siegwards_Fireplace                = 370004,
    Irithyll_PrePontiff                         = 370005,
    Irithyll_Pontiff_Sullyvahn                  = 370006,
    Irithyll_Bridge_Entrance                    = 370007,
    Irithyll_Tower_of_Yorshka                   = 370008,
    Irithyll_Pontiff_Hotspot                    = 370010,
    Irithyll_Darkmoon_Tomb                      = 370011,
    Irithyll_Anor_Londo                         = 370012,
    Irithyll_Aldrich,_Devourer_of_Gods          = 370012,
    //Catacombs of Carthus
    Catacombs_High_Lord_Wolnir                  = 380000,
    Catacombs_Entrance                          = 380001,
    Catacombs_Past_Boulder_Stairs               = 380002,
    Catacombs_Abyss_Watchers                    = 380020,
    Catacombs_Irithyll                          = 380021,
    //Demon Ruins
    Demon_Ruins_Old_Demon_King                  = 380010,
    Demon_Ruins_Abandoned_Tomb                  = 380012,
    Demon_Ruins_Horaces_cave                    = 380013,
    Demon_Ruins_Giant_Avelyn                    = 380014,
    Demon_Ruins_Old_Kings_Antechamber           = 380015,
    //Irithyll Dungeon
    Irithyll_Dungeon                            = 390000,
    Irithyll_Dungeon_Sleeping_Giant             = 390001,
    Irithyll_Dungeon_Lower_Dungeon              = 390002,
    Propaned_Capital                            = 390003,
    Propaned_Capital_PreYhorm                   = 390004,
    Propaned_Capital_Yhorm_the_Giant            = 390005,
    //Untended Graves
    Untended_Graves_Champion_Gundyr             = 400000,
    Untended_Graves                             = 400001,
    Dark_Firelink_Shrine                        = 400002,
    Untended_Graves_PostOceiros                 = 400010,
    //Kiln of The First Flame
    Kiln_of_Flame_Soul_of_Cinder                = 410000,
    Kiln_Preboss                                = 410001,
    Kiln_Flameless_Shrine                       = 410002,
    //Ashes of Ariandel
    AoA_Sister_Friede                           = 450000,
    AoA_Snowfield                               = 450001,
    AoA_Corvian_Settlement                      = 450002,
    AoA_Snowy_Mountain_Pass                     = 450003,
    AoA_Ariandel_Chapel                         = 450005,
    AoA_Champions_Gravetender                   = 450010,
    AoA_Depths_of_the_Painting                  = 450011,
    AoA_Priscillas_Arena                        = 450020,
    //The Ringed City
    TRC_Demon_Prince                            = 500000,
    TRC_The_Dreg_Heap                           = 500001,
    TRC_Earthen_Peak_Ruins                      = 500002,
    TRC_Within_the_Earthen_Peak_Ruins           = 500003,
    TRC_Spear_of_the_Church_Boss                = 510000,
    TRC_Mausoleum_Lookout                       = 510001,
    TRC_Ringed_Inner_Wall                       = 510002,
    TRC_Ringed_City_Streets                     = 510003,
    TRC_Shared_Grave                            = 510004,
    TRC_After_Bridge                            = 510005,
    TRC_Darkeater_Midir                         = 510010,
    TRC_PreMidir_Boss                           = 510011,
    TRC_Church_of_Filianore                     = 510020,
    TRC_Slave_Knight_Gael                       = 511000,
    TRC_Filianores_Rest                         = 511001,
    TRC_Broken_Church                           = 511010,
    //Undead Match
    Arena_Grand_Rooftop                         = 460000,
    Arena_Kiln_of_Flame                         = 470000,
    Arena_Dragon_Ruins                          = 530000,
    Arena_Round_Plaza                           = 540000
};

#endif
