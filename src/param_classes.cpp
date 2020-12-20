#include <voidworks/param_classes.h>

AtkParam_Pc::AtkParam_Pc(uint32_t id, uintptr_t address)
  : BaseParam(L"AtkParam_Pc", id, address) { }
void AtkParam_Pc::Hit0_Radius(float value)                { PatchFloat(0x00, value); }
void AtkParam_Pc::Hit1_Radius(float value)                { PatchFloat(0x00, value); }
void AtkParam_Pc::Hit2_Radius(float value)                { PatchFloat(0x00, value); }
void AtkParam_Pc::Hit3_Radius(float value)                { PatchFloat(0x00, value); }
void AtkParam_Pc::KnockbackDist(float value)              { PatchFloat(0x00, value); }
void AtkParam_Pc::HitStopTime(float value)                { PatchFloat(0x00, value); }
void AtkParam_Pc::SpecialEffectId0(int32_t value)         { Patch4Byte(0x00, value); }
void AtkParam_Pc::SpecialEffectId1(int32_t value)         { Patch4Byte(0x00, value); }
void AtkParam_Pc::SpecialEffectId2(int32_t value)         { Patch4Byte(0x00, value); }
void AtkParam_Pc::SpecialEffectId3(int32_t value)         { Patch4Byte(0x00, value); }
void AtkParam_Pc::SpecialEffectId4(int32_t value)         { Patch4Byte(0x00, value); }
void AtkParam_Pc::Hit0_DmyPoly1(int16_t value)            { Patch2Byte(0x00, value); }
void AtkParam_Pc::Hit1_DmyPoly1(int16_t value)            { Patch2Byte(0x00, value); }
void AtkParam_Pc::Hit2_DmyPoly1(int16_t value)            { Patch2Byte(0x00, value); }
void AtkParam_Pc::Hit3_DmyPoly1(int16_t value)            { Patch2Byte(0x00, value); }
void AtkParam_Pc::Hit0_DmyPoly2(int16_t value)            { Patch2Byte(0x00, value); }
void AtkParam_Pc::Hit1_DmyPoly2(int16_t value)            { Patch2Byte(0x00, value); }
void AtkParam_Pc::Hit2_DmyPoly2(int16_t value)            { Patch2Byte(0x00, value); }
void AtkParam_Pc::Hit3_DmyPoly2(int16_t value)            { Patch2Byte(0x00, value); }
void AtkParam_Pc::BlowingCorrection(int16_t value)        { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkPhysCorrection(int16_t value)        { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkMagCorrection(int16_t value)         { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkFireCorrection(int16_t value)        { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkThunCorrection(int16_t value)        { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkStamCorrection(int16_t value)        { Patch2Byte(0x00, value); }
void AtkParam_Pc::GuardAtkRateCorrection(int16_t value)   { Patch2Byte(0x00, value); }
void AtkParam_Pc::GuardBreakCorrection(int16_t value)     { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkThrowEscapeCorrection(int16_t value) { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkSuperArmorCorrection(int16_t value)  { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkPhys(int16_t value)                  { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkMag(int16_t value)                   { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkFire(int16_t value)                  { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkThun(int16_t value)                  { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkStam(int16_t value)                  { Patch2Byte(0x00, value); }
void AtkParam_Pc::GuardAtkRate(int16_t value)             { Patch2Byte(0x00, value); }
void AtkParam_Pc::GuardBreakRate(int16_t value)           { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkSuperArmor(int16_t value)            { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkThrowEscape(int16_t value)           { Patch2Byte(0x00, value); }
void AtkParam_Pc::AtkObj(int16_t value)                   { Patch2Byte(0x00, value); }
void AtkParam_Pc::GuardStaminaCutRate(int16_t value)      { Patch2Byte(0x00, value); }
void AtkParam_Pc::GuardRate(int16_t value)                { Patch2Byte(0x00, value); }
void AtkParam_Pc::ThrowTypeId(int16_t value)              { Patch2Byte(0x00, value); }
void AtkParam_Pc::Hit0_hitType(uint8_t value)             { PatchByte(0x00, value); }
void AtkParam_Pc::Hit1_hitType(uint8_t value)             { PatchByte(0x00, value); }
void AtkParam_Pc::Hit2_hitType(uint8_t value)             { PatchByte(0x00, value); }
void AtkParam_Pc::Hit3_hitType(uint8_t value)             { PatchByte(0x00, value); }
void AtkParam_Pc::DamageLevel(uint8_t value)              { PatchByte(0x00, value); }
void AtkParam_Pc::MapHitType(uint8_t value)               { PatchByte(0x00, value); }
void AtkParam_Pc::GuardCutCancelRate(uint8_t value)       { PatchByte(0x00, value); }
void AtkParam_Pc::AtkAttribute(uint8_t value)             { PatchByte(0x00, value); }
void AtkParam_Pc::SpecialAttributes(uint8_t value)        { PatchByte(0x00, value); }
void AtkParam_Pc::AttackType(uint8_t value)               { PatchByte(0x00, value); }
void AtkParam_Pc::AtkMaterial(uint8_t value)              { PatchByte(0x00, value); }
void AtkParam_Pc::AtkSize(uint8_t value)                  { PatchByte(0x00, value); }
void AtkParam_Pc::DefMaterial(uint8_t value)              { PatchByte(0x00, value); }
void AtkParam_Pc::DefSfxMaterial(uint8_t value)           { PatchByte(0x00, value); }
void AtkParam_Pc::HitSourceType(uint8_t value)            { PatchByte(0x00, value); }
void AtkParam_Pc::ThrowFlag(uint8_t value)                { PatchByte(0x00, value); }
void AtkParam_Pc::IsEffectDisabled(uint8_t value)         { PatchBinary(0x00, value, 2); }
void AtkParam_Pc::DoubleDamage(uint8_t value)             { PatchBinary(0x00, value, 6); }
void AtkParam_Pc::IsHitboxEnabled(uint8_t value)          { PatchBinary(0x00, value, 0); }
void AtkParam_Pc::IsHitBothTeams(uint8_t value)           { PatchBinary(0x00, value, 1); }
void AtkParam_Pc::IsSelfHit(uint8_t value)                { PatchBinary(0x00, value, 2); }
void AtkParam_Pc::CameraActOnHit(int32_t value)           { Patch4Byte(0x00, value); }
void AtkParam_Pc::ThrowCameraAct(int32_t value)           { Patch4Byte(0x00, value); }

Bullet::Bullet(uint32_t id, uintptr_t address)
  : BaseParam(L"Bullet", id, address) { }
void Bullet::AtkId_Bullet(int32_t value)                { Patch4Byte(0x00, value); }
void Bullet::SfxId_Bullet(int32_t value)                { Patch4Byte(0x00, value); }
void Bullet::SfxId_Hit(int32_t value)                   { Patch4Byte(0x00, value); }
void Bullet::SfxId_Flick(int32_t value)                 { Patch4Byte(0x00, value); }
void Bullet::Life(float value)                          { PatchFloat(0x00, value); }
void Bullet::Dist(float value)                          { PatchFloat(0x00, value); }
void Bullet::ShootInterval(float value)                 { PatchFloat(0x00, value); }
void Bullet::GravityInRange(int32_t value)              { Patch4Byte(0x00, value); }
void Bullet::GravityOutRange(float value)               { PatchFloat(0x00, value); }
void Bullet::HormingStopRange(float value)              { PatchFloat(0x00, value); }
void Bullet::InitVellocity(float value)                 { PatchFloat(0x00, value); }
void Bullet::AccelInRange(float value)                  { PatchFloat(0x00, value); }
void Bullet::AccelOutRange(float value)                 { PatchFloat(0x00, value); }
void Bullet::MaxVellocity(float value)                  { PatchFloat(0x00, value); }
void Bullet::MinVellocity(float value)                  { PatchFloat(0x00, value); }
void Bullet::AccelTime(float value)                     { PatchFloat(0x00, value); }
void Bullet::HomingBeginDist(float value)               { PatchFloat(0x00, value); }
void Bullet::HitRadius(float value)                     { PatchFloat(0x00, value); }
void Bullet::HitRadiusMax(float value)                  { PatchFloat(0x00, value); }
void Bullet::SpreadTime(float value)                    { PatchFloat(0x00, value); }
void Bullet::ExpDelay(float value)                      { PatchFloat(0x00, value); }
void Bullet::HormingOffsetRange(float value)            { PatchFloat(0x00, value); }
void Bullet::DmgHitRecordLifeTime(float value)          { PatchFloat(0x00, value); }
void Bullet::ExternalForce(int32_t value)               { Patch4Byte(0x00, value); }
void Bullet::SpEffectIDForShooter(int32_t value)        { Patch4Byte(0x00, value); }
void Bullet::AutoSearchNPCThinkID(int32_t value)        { Patch4Byte(0x00, value); }
void Bullet::HitBulletID(int32_t value)                 { Patch4Byte(0x00, value); }
void Bullet::SpEffectId0(int32_t value)                 { Patch4Byte(0x00, value); }
void Bullet::SpEffectId1(int32_t value)                 { Patch4Byte(0x00, value); }
void Bullet::SpEffectId2(int32_t value)                 { Patch4Byte(0x00, value); }
void Bullet::SpEffectId3(int32_t value)                 { Patch4Byte(0x00, value); }
void Bullet::SpEffectId4(int32_t value)                 { Patch4Byte(0x00, value); }
void Bullet::NumShoot(int16_t value)                    { Patch2Byte(0x00, value); }
void Bullet::HomingAngle(int16_t value)                 { Patch2Byte(0x00, value); }
void Bullet::ShootAngle(int16_t value)                  { Patch2Byte(0x00, value); }
void Bullet::ShootAngleInterval(int16_t value)          { Patch2Byte(0x00, value); }
void Bullet::ShootAngleXInterval(int16_t value)         { Patch2Byte(0x00, value); }
void Bullet::DamageDamp(uint8_t value)                  { PatchByte(0x00, value); }
void Bullet::SpelDamageDamp(uint8_t value)              { PatchByte(0x00, value); }
void Bullet::FireDamageDamp(uint8_t value)              { PatchByte(0x00, value); }
void Bullet::ThunderDamageDamp(uint8_t value)           { PatchByte(0x00, value); }
void Bullet::StaminaDamp(uint8_t value)                 { PatchByte(0x00, value); }
void Bullet::KnockbackDamp(uint8_t value)               { PatchByte(0x00, value); }
void Bullet::ShootAngleXZ(uint8_t value)                { PatchByte(0x00, value); }
void Bullet::LockShootLimitAng(uint8_t value)           { PatchByte(0x00, value); }
void Bullet::IsPenetrate(uint8_t value)                 { PatchByte(0x00, value); }
void Bullet::PrevVelocityDirRate(uint8_t value)         { PatchByte(0x00, value); }
void Bullet::AtkAttribute(uint8_t value)                { PatchByte(0x00, value); }
void Bullet::SpAttribute(uint8_t value)                 { PatchByte(0x00, value); }
void Bullet::Material_AttackType(uint8_t value)         { PatchByte(0x00, value); }
void Bullet::Material_AttackMaterial(uint8_t value)     { PatchByte(0x00, value); }
void Bullet::Material_Size(uint8_t value)               { PatchByte(0x00, value); }
void Bullet::LaunchConditionType(uint8_t value)         { PatchByte(0x00, value); }
void Bullet::FollowType(uint8_t value)                  { PatchBinary(0x00, value, 0); }
void Bullet::EmittePosType(uint8_t value)               { PatchBinary(0x00, value, 1); }
void Bullet::IsAttackSFX(uint8_t value)                 { PatchBinary(0x00, value, 2); }
void Bullet::IsEndlessHit(uint8_t value)                { PatchBinary(0x00, value, 3); }
void Bullet::CamAngleShoot(uint8_t value)               { PatchBinary(0x00, value, 4); }
void Bullet::IsSpawnAtClosestEnemy(uint8_t value)       { PatchBinary(0x00, value, 5); }
void Bullet::IsPenetrateMap(uint8_t value)              { PatchBinary(0x00, value, 0); }
void Bullet::IsHitBothTeam(uint8_t value)               { PatchBinary(0x00, value, 1); }
void Bullet::IsUseSharedHitList(uint8_t value)          { PatchBinary(0x00, value, 2); }
void Bullet::IsUseMultiDmyPolyIfPlace(uint8_t value)    { PatchBinary(0x00, value, 3); }
void Bullet::AttachEffectType(uint8_t value)            { PatchBinary(0x00, value, 4); }
void Bullet::IsHitForceBullet(uint8_t value)            { PatchBinary(0x00, value, 5); }
void Bullet::IsIgnoreSfxIfHitWater(uint8_t value)       { PatchBinary(0x00, value, 6); }
void Bullet::IsIgnoreMoveStateIfHitWater(uint8_t value) { PatchBinary(0x00, value, 7); }
void Bullet::IsHitDarkForceBullet(uint8_t value)        { PatchBinary(0x00, value, 0); }
void Bullet::SpellParriable(uint8_t value)              { PatchBinary(0x00, value, 1); }
void Bullet::AutoFollowTarget(uint8_t value)            { PatchBinary(0x00, value, 4); }
void Bullet::DarkDamageDamp(uint8_t value)              { PatchByte(0x00, value); }
void Bullet::ConditionByte(uint8_t value)               { PatchByte(0x00, value); }
void Bullet::ConditionByte1(uint8_t value)              { PatchByte(0x00, value); }
void Bullet::Z_Homing(float value)                      { PatchFloat(0x00, value); }
void Bullet::HomingAngleCameraXY(float value)           { PatchFloat(0x00, value); }
void Bullet::HomingAngleCameraZ(float value)            { PatchFloat(0x00, value); }
void Bullet::EmitterBulletId(int32_t value)             { Patch4Byte(0x00, value); }
void Bullet::EmitterShootInterval(float value)          { PatchFloat(0x00, value); }
void Bullet::EmitterSpawnInterval(float value)          { PatchFloat(0x00, value); }
void Bullet::EmitterDelayUntilShot(float value)         { PatchFloat(0x00, value); }
void Bullet::BulletCreateLimitId(uint8_t value)         { PatchByte(0x00, value); }
void Bullet::TargetHitstop(uint8_t value)               { PatchBinary(0x00, value, 1); }
void Bullet::TargetPenetrate(uint8_t value)             { PatchBinary(0x00, value, 4); }
void Bullet::FreeAim(uint8_t value)                     { PatchBinary(0x00, value, 5); }
void Bullet::FollowTypeNumshoot(uint8_t value)          { PatchBinary(0x00, value, 6); }
void Bullet::ObjectId(int32_t value)                    { Patch4Byte(0x00, value); }
void Bullet::ExtendDist(float value)                    { PatchFloat(0x00, value); }
void Bullet::ExtendLife(uint8_t value)                  { PatchByte(0x00, value); }
void Bullet::AdjustAngle(uint8_t value)                 { PatchByte(0x00, value); }

EquipParamGoods::EquipParamGoods(uint32_t id, uintptr_t address)
  : BaseParam(L"EquipParamGoods", id, address) { }
void EquipParamGoods::RefId(int32_t value)                        { Patch4Byte(0x00, value); }
void EquipParamGoods::SfxVariationId(int32_t value)               { Patch4Byte(0x00, value); }
void EquipParamGoods::Weight(float value)                         { PatchFloat(0x00, value); }
void EquipParamGoods::BasicPrice(int32_t value)                   { Patch4Byte(0x00, value); }
void EquipParamGoods::SellValue(int32_t value)                    { Patch4Byte(0x00, value); }
void EquipParamGoods::BehaviorId(int32_t value)                   { Patch4Byte(0x00, value); }
void EquipParamGoods::ReplaceItemId(int32_t value)                { Patch4Byte(0x00, value); }
void EquipParamGoods::SortId(int32_t value)                       { Patch4Byte(0x00, value); }
void EquipParamGoods::QwcId(int32_t value)                        { Patch4Byte(0x00, value); }
void EquipParamGoods::YesNoDialogMessageId(int32_t value)         { Patch4Byte(0x00, value); }
void EquipParamGoods::MagicId(int32_t value)                      { Patch4Byte(0x00, value); }
void EquipParamGoods::IconId(int16_t value)                       { Patch2Byte(0x00, value); }
void EquipParamGoods::ModelId(int16_t value)                      { Patch2Byte(0x00, value); }
void EquipParamGoods::ShopLv(int16_t value)                       { Patch2Byte(0x00, value); }
void EquipParamGoods::CompTrophySedId(int16_t value)              { Patch2Byte(0x00, value); }
void EquipParamGoods::TrophySeqId(int16_t value)                  { Patch2Byte(0x00, value); }
void EquipParamGoods::MaxNum(int16_t value)                       { Patch2Byte(0x00, value); }
void EquipParamGoods::ConsumeHeroPoint(uint8_t value)             { PatchByte(0x00, value); }
void EquipParamGoods::OverDexterity(uint8_t value)                { PatchByte(0x00, value); }
void EquipParamGoods::GoodsType(uint8_t value)                    { PatchByte(0x00, value); }
void EquipParamGoods::RefCategory(uint8_t value)                  { PatchByte(0x00, value); }
void EquipParamGoods::SpEffectCategory(uint8_t value)             { PatchByte(0x00, value); }
void EquipParamGoods::GoodsUseAnim(uint8_t value)                 { PatchByte(0x00, value); }
void EquipParamGoods::OpmeMenuType(uint8_t value)                 { PatchByte(0x00, value); }
void EquipParamGoods::UseLimitCategory(uint8_t value)             { PatchByte(0x00, value); }
void EquipParamGoods::ReplaceCategory(uint8_t value)              { PatchByte(0x00, value); }
void EquipParamGoods::VowType0(uint8_t value)                     { PatchBinary(0x00, value, 0); }
void EquipParamGoods::VowType1(uint8_t value)                     { PatchBinary(0x00, value, 1); }
void EquipParamGoods::VowType2(uint8_t value)                     { PatchBinary(0x00, value, 2); }
void EquipParamGoods::VowType3(uint8_t value)                     { PatchBinary(0x00, value, 3); }
void EquipParamGoods::VowType4(uint8_t value)                     { PatchBinary(0x00, value, 4); }
void EquipParamGoods::VowType5(uint8_t value)                     { PatchBinary(0x00, value, 5); }
void EquipParamGoods::VowType6(uint8_t value)                     { PatchBinary(0x00, value, 6); }
void EquipParamGoods::VowType7(uint8_t value)                     { PatchBinary(0x00, value, 7); }
void EquipParamGoods::VowType8(uint8_t value)                     { PatchBinary(0x00, value, 0); }
void EquipParamGoods::VowType9(uint8_t value)                     { PatchBinary(0x00, value, 1); }
void EquipParamGoods::VowType10(uint8_t value)                    { PatchBinary(0x00, value, 2); }
void EquipParamGoods::VowType11(uint8_t value)                    { PatchBinary(0x00, value, 3); }
void EquipParamGoods::VowType12(uint8_t value)                    { PatchBinary(0x00, value, 4); }
void EquipParamGoods::VowType13(uint8_t value)                    { PatchBinary(0x00, value, 5); }
void EquipParamGoods::VowType14(uint8_t value)                    { PatchBinary(0x00, value, 6); }
void EquipParamGoods::VowType15(uint8_t value)                    { PatchBinary(0x00, value, 7); }
void EquipParamGoods::Enable_live(uint8_t value)                  { PatchBinary(0x00, value, 0); }
void EquipParamGoods::Enable_gray(uint8_t value)                  { PatchBinary(0x00, value, 1); }
void EquipParamGoods::Enable_white(uint8_t value)                 { PatchBinary(0x00, value, 2); }
void EquipParamGoods::Enable_black(uint8_t value)                 { PatchBinary(0x00, value, 3); }
void EquipParamGoods::Enable_multi(uint8_t value)                 { PatchBinary(0x00, value, 4); }
void EquipParamGoods::Disable_offline(uint8_t value)              { PatchBinary(0x00, value, 5); }
void EquipParamGoods::IsEquip(uint8_t value)                      { PatchBinary(0x00, value, 6); }
void EquipParamGoods::IsConsume(uint8_t value)                    { PatchBinary(0x00, value, 7); }
void EquipParamGoods::IsAutoEquip(uint8_t value)                  { PatchBinary(0x00, value, 0); }
void EquipParamGoods::IsEstablishment(uint8_t value)              { PatchBinary(0x00, value, 1); }
void EquipParamGoods::IsOnlyOne(uint8_t value)                    { PatchBinary(0x00, value, 2); }
void EquipParamGoods::IsDiscard(uint8_t value)                    { PatchBinary(0x00, value, 3); }
void EquipParamGoods::IsDeposit(uint8_t value)                    { PatchBinary(0x00, value, 4); }
void EquipParamGoods::IsDisableHand(uint8_t value)                { PatchBinary(0x00, value, 5); }
void EquipParamGoods::IsTravelItem(uint8_t value)                 { PatchBinary(0x00, value, 6); }
void EquipParamGoods::IsSuppleItem(uint8_t value)                 { PatchBinary(0x00, value, 7); }
void EquipParamGoods::IsFullSuppleItem(uint8_t value)             { PatchBinary(0x00, value, 0); }
void EquipParamGoods::IsEnhance1(uint8_t value)                   { PatchBinary(0x00, value, 1); }
void EquipParamGoods::IsFixItem(uint8_t value)                    { PatchBinary(0x00, value, 2); }
void EquipParamGoods::DisableMultiDropShare(uint8_t value)        { PatchBinary(0x00, value, 3); }
void EquipParamGoods::DisableUseAtColiseum(uint8_t value)         { PatchBinary(0x00, value, 4); }
void EquipParamGoods::DisableUseAtOutOfColiseum(uint8_t value)    { PatchBinary(0x00, value, 5); }
void EquipParamGoods::RefId2(int32_t value)                       { Patch4Byte(0x00, value); }
void EquipParamGoods::DamageScaling(int32_t value)                { Patch4Byte(0x00, value); }
void EquipParamGoods::VagrantItemLotId(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamGoods::VagrantBonusEneDropItemLotId(int32_t value) { Patch4Byte(0x00, value); }
void EquipParamGoods::VagrantItemEneDropItemLotId(int32_t value)  { Patch4Byte(0x00, value); }
void EquipParamGoods::SfxId(int32_t value)                        { Patch4Byte(0x00, value); }
void EquipParamGoods::SfxId1(int32_t value)                       { Patch4Byte(0x00, value); }
void EquipParamGoods::SfxId2(int32_t value)                       { Patch4Byte(0x00, value); }
void EquipParamGoods::IsUse(uint8_t value)                        { PatchBinary(0x00, value, 0); }
void EquipParamGoods::LadderUse(uint8_t value)                    { PatchBinary(0x00, value, 2); }
void EquipParamGoods::IsUseSelected(uint8_t value)                { PatchBinary(0x00, value, 4); }
void EquipParamGoods::IsEnhanceLeft(uint8_t value)                { PatchBinary(0x00, value, 5); }
void EquipParamGoods::BlockUse(uint8_t value)                     { PatchBinary(0x00, value, 7); }
void EquipParamGoods::IsDrop(uint8_t value)                       { PatchByte(0x00, value); }
void EquipParamGoods::StorageMax(int16_t value)                   { Patch2Byte(0x00, value); }
void EquipParamGoods::ShopPrice(int32_t value)                    { Patch4Byte(0x00, value); }
void EquipParamGoods::FPCost(int16_t value)                       { Patch2Byte(0x00, value); }
void EquipParamGoods::SpecialRestrict(uint8_t value)              { PatchByte(0x00, value); }
void EquipParamGoods::RefId1(int32_t value)                       { Patch4Byte(0x00, value); }

EquipParamWeapon::EquipParamWeapon(uint32_t id, uintptr_t address)
  : BaseParam(L"EquipParamWeapon", id, address) { }
void EquipParamWeapon::BehaviorVariationId(int32_t value)          { Patch4Byte(0x00, value); }
void EquipParamWeapon::SortId(int32_t value)                       { Patch4Byte(0x00, value); }
void EquipParamWeapon::WanderingEquipId(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamWeapon::Weight(float value)                         { PatchFloat(0x00, value); }
void EquipParamWeapon::WeaponWeightRate(float value)               { PatchFloat(0x00, value); }
void EquipParamWeapon::FixPrice(int32_t value)                     { Patch4Byte(0x00, value); }
void EquipParamWeapon::BasicPrice(int32_t value)                   { Patch4Byte(0x00, value); }
void EquipParamWeapon::SellValue(int32_t value)                    { Patch4Byte(0x00, value); }
void EquipParamWeapon::CorrectStrength(float value)                { PatchFloat(0x00, value); }
void EquipParamWeapon::CorrectAgility(float value)                 { PatchFloat(0x00, value); }
void EquipParamWeapon::CorrectMagic(float value)                   { PatchFloat(0x00, value); }
void EquipParamWeapon::CorrectFaith(float value)                   { PatchFloat(0x00, value); }
void EquipParamWeapon::PhysGuardCutRate(float value)               { PatchFloat(0x00, value); }
void EquipParamWeapon::MagGuardCutRate(float value)                { PatchFloat(0x00, value); }
void EquipParamWeapon::FireGuardCutRate(float value)               { PatchFloat(0x00, value); }
void EquipParamWeapon::ThunGuardCutRate(float value)               { PatchFloat(0x00, value); }
void EquipParamWeapon::SpEffectBehaviorId(int32_t value)           { Patch4Byte(0x00, value); }
void EquipParamWeapon::SpEffectBehaviorId1(int32_t value)          { Patch4Byte(0x00, value); }
void EquipParamWeapon::SpEffectBehaviorId2(int32_t value)          { Patch4Byte(0x00, value); }
void EquipParamWeapon::ResidentSpEffectId(int32_t value)           { Patch4Byte(0x00, value); }
void EquipParamWeapon::ResidentSpEffectId1(int32_t value)          { Patch4Byte(0x00, value); }
void EquipParamWeapon::ResidentSpEffectId2(int32_t value)          { Patch4Byte(0x00, value); }
void EquipParamWeapon::MaterialSetId(int32_t value)                { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep(int32_t value)               { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep1(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep2(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep3(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep4(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep5(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep6(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep7(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep8(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep9(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep10(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep11(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep12(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep13(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep14(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamWeapon::OriginEquipWep15(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamWeapon::AntiDemonDamageRate(float value)            { PatchFloat(0x00, value); }
void EquipParamWeapon::AntUndeadDamageRate(float value)            { PatchFloat(0x00, value); }
void EquipParamWeapon::AntHollowDamageRate(float value)            { PatchFloat(0x00, value); }
void EquipParamWeapon::AntAbyssalDamageRate(float value)           { PatchFloat(0x00, value); }
void EquipParamWeapon::VagrantItemLotId(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamWeapon::VagrantBonusEneDropItemLotId(int32_t value) { Patch4Byte(0x00, value); }
void EquipParamWeapon::VagrantItemEneDropItemLotId(int32_t value)  { Patch4Byte(0x00, value); }
void EquipParamWeapon::EquipModelId(int16_t value)                 { Patch2Byte(0x00, value); }
void EquipParamWeapon::IconId(int16_t value)                       { Patch2Byte(0x00, value); }
void EquipParamWeapon::Durability(int16_t value)                   { Patch2Byte(0x00, value); }
void EquipParamWeapon::DurabilityMax(int16_t value)                { Patch2Byte(0x00, value); }
void EquipParamWeapon::AttackThrowEscape(int16_t value)            { Patch2Byte(0x00, value); }
void EquipParamWeapon::ParryDamageLife(int16_t value)              { Patch2Byte(0x00, value); }
void EquipParamWeapon::AttackBasePhysics(int16_t value)            { Patch2Byte(0x00, value); }
void EquipParamWeapon::AttackBaseMagic(int16_t value)              { Patch2Byte(0x00, value); }
void EquipParamWeapon::AttackBaseFire(int16_t value)               { Patch2Byte(0x00, value); }
void EquipParamWeapon::AttackBaseThunder(int16_t value)            { Patch2Byte(0x00, value); }
void EquipParamWeapon::AttackBaseStamina(int16_t value)            { Patch2Byte(0x00, value); }
void EquipParamWeapon::SaWeaponDamage(int16_t value)               { Patch2Byte(0x00, value); }
void EquipParamWeapon::SaDurability(int16_t value)                 { Patch2Byte(0x00, value); }
void EquipParamWeapon::GuardAngle(int16_t value)                   { Patch2Byte(0x00, value); }
void EquipParamWeapon::StaminaGuardDef(int16_t value)              { Patch2Byte(0x00, value); }
void EquipParamWeapon::ReinforceTypeId(int16_t value)              { Patch2Byte(0x00, value); }
void EquipParamWeapon::TrophySGradeId(int16_t value)               { Patch2Byte(0x00, value); }
void EquipParamWeapon::TrophySeqId(int16_t value)                  { Patch2Byte(0x00, value); }
void EquipParamWeapon::ThrowAtkRate(int16_t value)                 { Patch2Byte(0x00, value); }
void EquipParamWeapon::BowDistRate(int16_t value)                  { Patch2Byte(0x00, value); }
void EquipParamWeapon::EquipModelCategory(uint8_t value)           { PatchByte(0x00, value); }
void EquipParamWeapon::EquipModelGender(uint8_t value)             { PatchByte(0x00, value); }
void EquipParamWeapon::WeaponCategory(uint8_t value)               { PatchByte(0x00, value); }
void EquipParamWeapon::WepmotionCategory(uint8_t value)            { PatchByte(0x00, value); }
void EquipParamWeapon::GuardmotionCategory(uint8_t value)          { PatchByte(0x00, value); }
void EquipParamWeapon::AtkMaterial(uint8_t value)                  { PatchByte(0x00, value); }
void EquipParamWeapon::DefMaterial(uint8_t value)                  { PatchByte(0x00, value); }
void EquipParamWeapon::DefSfxMaterial(uint8_t value)               { PatchByte(0x00, value); }
void EquipParamWeapon::CorrectType(uint8_t value)                  { PatchByte(0x00, value); }
void EquipParamWeapon::SpAttribute(uint8_t value)                  { PatchByte(0x00, value); }
void EquipParamWeapon::SpAtkcategory(int16_t value)                { Patch2Byte(0x00, value); }
void EquipParamWeapon::WepmotionOneHandId(uint8_t value)           { PatchByte(0x00, value); }
void EquipParamWeapon::WepmotionBothHandId(uint8_t value)          { PatchByte(0x00, value); }
void EquipParamWeapon::ProperStrength(uint8_t value)               { PatchByte(0x00, value); }
void EquipParamWeapon::ProperAgility(uint8_t value)                { PatchByte(0x00, value); }
void EquipParamWeapon::ProperMagic(uint8_t value)                  { PatchByte(0x00, value); }
void EquipParamWeapon::ProperFaith(uint8_t value)                  { PatchByte(0x00, value); }
void EquipParamWeapon::OverStrength(uint8_t value)                 { PatchByte(0x00, value); }
void EquipParamWeapon::AttackBaseParry(uint8_t value)              { PatchByte(0x00, value); }
void EquipParamWeapon::DefenseBaseParry(uint8_t value)             { PatchByte(0x00, value); }
void EquipParamWeapon::GuardBaseRepel(uint8_t value)               { PatchByte(0x00, value); }
void EquipParamWeapon::AttackBaseRepel(uint8_t value)              { PatchByte(0x00, value); }
void EquipParamWeapon::GuardCutCancelRate(uint8_t value)           { PatchByte(0x00, value); }
void EquipParamWeapon::GuardLevel(uint8_t value)                   { PatchByte(0x00, value); }
void EquipParamWeapon::SlashGuardCutRate(uint8_t value)            { PatchByte(0x00, value); }
void EquipParamWeapon::BlowGuardCutRate(uint8_t value)             { PatchByte(0x00, value); }
void EquipParamWeapon::ThrustGuardCutRate(uint8_t value)           { PatchByte(0x00, value); }
void EquipParamWeapon::PoisonGuardResist(uint8_t value)            { PatchByte(0x00, value); }
void EquipParamWeapon::DiseaseGuardResist(uint8_t value)           { PatchByte(0x00, value); }
void EquipParamWeapon::BloodGuardResist(uint8_t value)             { PatchByte(0x00, value); }
void EquipParamWeapon::CurseGuardResist(uint8_t value)             { PatchByte(0x00, value); }
void EquipParamWeapon::IsDurabilityDivergence(uint8_t value)       { PatchByte(0x0000, value); }
void EquipParamWeapon::RightHandEquipable(uint8_t value)           { PatchBinary(0x0000, value, 0); }
void EquipParamWeapon::LeftHandEquipable(uint8_t value)            { PatchBinary(0x0000, value, 1); }
void EquipParamWeapon::BothHandEquipable(uint8_t value)            { PatchBinary(0x0000, value, 2); }
void EquipParamWeapon::ArrowSlotEquipable(uint8_t value)           { PatchBinary(0x0000, value, 3); }
void EquipParamWeapon::BoltSlotEquipable(uint8_t value)            { PatchBinary(0x0000, value, 4); }
void EquipParamWeapon::EnableGuard(uint8_t value)                  { PatchBinary(0x0000, value, 5); }
void EquipParamWeapon::EnableParry(uint8_t value)                  { PatchBinary(0x0000, value, 6); }
void EquipParamWeapon::EnableMagic(uint8_t value)                  { PatchBinary(0x0000, value, 7); }
void EquipParamWeapon::EnablePyromancy(uint8_t value)              { PatchBinary(0x0000, value, 0); }
void EquipParamWeapon::EnableMiracle(uint8_t value)                { PatchBinary(0x0000, value, 1); }
void EquipParamWeapon::EnableVowMagic(uint8_t value)               { PatchBinary(0x0000, value, 2); }
void EquipParamWeapon::IsNormalAttackType(uint8_t value)           { PatchBinary(0x0000, value, 3); }
void EquipParamWeapon::IsBlowAttackType(uint8_t value)             { PatchBinary(0x0000, value, 4); }
void EquipParamWeapon::IsSlashAttackType(uint8_t value)            { PatchBinary(0x0000, value, 5); }
void EquipParamWeapon::IsThrustAttackType(uint8_t value)           { PatchBinary(0x0000, value, 6); }
void EquipParamWeapon::IsEnhance(uint8_t value)                    { PatchBinary(0x0000, value, 7); }
void EquipParamWeapon::IsLuckCorrect(uint8_t value)                { PatchBinary(0x0000, value, 0); }
void EquipParamWeapon::IsCustom(uint8_t value)                     { PatchBinary(0x0000, value, 1); }
void EquipParamWeapon::DisableBaseChangeReset(uint8_t value)       { PatchBinary(0x0000, value, 2); }
void EquipParamWeapon::DisableRepair(uint8_t value)                { PatchBinary(0x0000, value, 3); }
void EquipParamWeapon::IsDarkHand(uint8_t value)                   { PatchBinary(0x0000, value, 4); }
void EquipParamWeapon::SimpleModelForDlc(uint8_t value)            { PatchBinary(0x0000, value, 5); }
void EquipParamWeapon::UbytelanternWep(uint8_t value)              { PatchBinary(0x0000, value, 6); }
void EquipParamWeapon::IsVersusGhostWep(uint8_t value)             { PatchBinary(0x0000, value, 7); }
void EquipParamWeapon::BaseChangeCategory(uint8_t value)           { PatchBinary(0x0000, value, 0); }
void EquipParamWeapon::BaseChangeCategory1(uint8_t value)          { PatchBinary(0x0000, value, 1); }
void EquipParamWeapon::BaseChangeCategory2(uint8_t value)          { PatchBinary(0x0000, value, 2); }
void EquipParamWeapon::BaseChangeCategory3(uint8_t value)          { PatchBinary(0x0000, value, 3); }
void EquipParamWeapon::BaseChangeCategory4(uint8_t value)          { PatchBinary(0x0000, value, 4); }
void EquipParamWeapon::BaseChangeCategory5(uint8_t value)          { PatchBinary(0x0000, value, 5); }
void EquipParamWeapon::IsDragonSlayer(uint8_t value)               { PatchBinary(0x0000, value, 6); }
void EquipParamWeapon::IsDeposit(uint8_t value)                    { PatchBinary(0x0000, value, 7); }
void EquipParamWeapon::DisableMultiDropShare(uint8_t value)        { PatchBinary(0x0000, value, 0); }
void EquipParamWeapon::IsDiscard(uint8_t value)                    { PatchBinary(0x0000, value, 1); }
void EquipParamWeapon::IsDrop(uint8_t value)                       { PatchBinary(0x0000, value, 2); }
void EquipParamWeapon::WeaponPosition(int32_t value)               { Patch4Byte(0x0000, value); }
void EquipParamWeapon::DualWeaponType(uint8_t value)               { PatchByte(0x0000, value); }
void EquipParamWeapon::CorrectTypeMagic(uint8_t value)             { PatchByte(0x0000, value); }
void EquipParamWeapon::CorrectTypeFire(uint8_t value)              { PatchByte(0x0000, value); }
void EquipParamWeapon::CorrectTypeThunder(uint8_t value)           { PatchByte(0x0000, value); }
void EquipParamWeapon::DarkGuardCutRate(float value)               { PatchFloat(0x0000, value); }
void EquipParamWeapon::AttackBaseDark(int16_t value)               { Patch2Byte(0x0000, value); }
void EquipParamWeapon::CorrectTypeDark(uint8_t value)              { PatchByte(0x0000, value); }
void EquipParamWeapon::FrostGuardResist(uint8_t value)             { PatchByte(0x0000, value); }
void EquipParamWeapon::SwordArt(int32_t value)                     { Patch4Byte(0x0000, value); }
void EquipParamWeapon::CorrectLuck(float value)                    { PatchFloat(0x0000, value); }
void EquipParamWeapon::QuiverModel(int32_t value)                  { Patch4Byte(0x0000, value); }
void EquipParamWeapon::CategoryName(int16_t value)                 { Patch2Byte(0x0000, value); }
void EquipParamWeapon::SfxId0(int32_t value)                       { Patch4Byte(0x0000, value); }
void EquipParamWeapon::SfxId1(int32_t value)                       { Patch4Byte(0x0000, value); }
void EquipParamWeapon::SfxId2(int32_t value)                       { Patch4Byte(0x0000, value); }
void EquipParamWeapon::SfxId3(int32_t value)                       { Patch4Byte(0x0000, value); }
void EquipParamWeapon::SfxPos0(int32_t value)                      { Patch4Byte(0x0000, value); }
void EquipParamWeapon::SfxPos1(int32_t value)                      { Patch4Byte(0x0000, value); }
void EquipParamWeapon::SfxPos2(int32_t value)                      { Patch4Byte(0x0000, value); }
void EquipParamWeapon::SfxPos3(int32_t value)                      { Patch4Byte(0x0000, value); }
void EquipParamWeapon::StaminaConsumption(float value)             { PatchFloat(0x0000, value); }
void EquipParamWeapon::AttackElementCorrect(int32_t value)         { Patch4Byte(0x0000, value); }
void EquipParamWeapon::ShopPrice(int32_t value)                    { Patch4Byte(0x0000, value); }
void EquipParamWeapon::StackSize(uint8_t value)                    { PatchByte(0x0000, value); }

EquipParamProtector::EquipParamProtector(uint32_t id, uintptr_t address)
  : BaseParam(L"EquipParamProtector", id, address) { }
void EquipParamProtector::SortId(int32_t value)                       { Patch4Byte(0x00, value); }
void EquipParamProtector::WanderingEquipId(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamProtector::VagrantItemLotId(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamProtector::VagrantBonusEneDropItemLotId(int32_t value) { Patch4Byte(0x00, value); }
void EquipParamProtector::VagrantItemEneDropItemLotId(int32_t value)  { Patch4Byte(0x00, value); }
void EquipParamProtector::FixPrice(int32_t value)                     { Patch4Byte(0x00, value); }
void EquipParamProtector::BasicPrice(int32_t value)                   { Patch4Byte(0x00, value); }
void EquipParamProtector::SellValue(int32_t value)                    { Patch4Byte(0x00, value); }
void EquipParamProtector::Weight(float value)                         { PatchFloat(0x00, value); }
void EquipParamProtector::ResidentSpEffectId(int32_t value)           { Patch4Byte(0x00, value); }
void EquipParamProtector::ResidentSpEffectId2(int32_t value)          { Patch4Byte(0x00, value); }
void EquipParamProtector::ResidentSpEffectId3(int32_t value)          { Patch4Byte(0x00, value); }
void EquipParamProtector::MaterialSetId(int32_t value)                { Patch4Byte(0x00, value); }
void EquipParamProtector::PartsDamageRate(float value)                { PatchFloat(0x00, value); }
void EquipParamProtector::CorectSARecover(float value)                { PatchFloat(0x00, value); }
void EquipParamProtector::OriginEquipPro(int32_t value)               { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro1(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro2(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro3(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro4(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro5(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro6(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro7(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro8(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro9(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro10(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro11(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro12(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro13(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro14(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamProtector::OriginEquipPro15(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamProtector::FaceScaleM_ScaleX(float value)              { PatchFloat(0x00, value); }
void EquipParamProtector::FaceScaleM_ScaleZ(float value)              { PatchFloat(0x00, value); }
void EquipParamProtector::FaceScaleM_MaxX(float value)                { PatchFloat(0x00, value); }
void EquipParamProtector::FaceScaleM_MaxZ(float value)                { PatchFloat(0x00, value); }
void EquipParamProtector::FaceScaleF_ScaleX(float value)              { PatchFloat(0x00, value); }
void EquipParamProtector::FaceScaleF_ScaleZ(float value)              { PatchFloat(0x00, value); }
void EquipParamProtector::FaceScaleF_MaxX(float value)                { PatchFloat(0x00, value); }
void EquipParamProtector::FaceScaleF_MaxZ(float value)                { PatchFloat(0x00, value); }
void EquipParamProtector::QwcId(int32_t value)                        { Patch4Byte(0x00, value); }
void EquipParamProtector::EquipModelId(int16_t value)                 { Patch2Byte(0x00, value); }
void EquipParamProtector::IconIdM(int16_t value)                      { Patch2Byte(0x00, value); }
void EquipParamProtector::IconIdF(int32_t value)                      { Patch4Byte(0x00, value); }
void EquipParamProtector::KnockbackBounceRate(int16_t value)          { Patch2Byte(0x00, value); }
void EquipParamProtector::Durability(int16_t value)                   { Patch2Byte(0x00, value); }
void EquipParamProtector::DurabilityMax(int16_t value)                { Patch2Byte(0x00, value); }
void EquipParamProtector::SaDurability(int16_t value)                 { Patch2Byte(0x00, value); }
void EquipParamProtector::DefFlickPower(int16_t value)                { Patch2Byte(0x00, value); }
void EquipParamProtector::DefensePhysics(int16_t value)               { Patch2Byte(0x00, value); }
void EquipParamProtector::DefenseMagic(int16_t value)                 { Patch2Byte(0x00, value); }
void EquipParamProtector::DefenseFire(int16_t value)                  { Patch2Byte(0x00, value); }
void EquipParamProtector::DefenseThunder(int16_t value)               { Patch2Byte(0x00, value); }
void EquipParamProtector::DefenseSlash(int16_t value)                 { Patch2Byte(0x00, value); }
void EquipParamProtector::DefenseBlow(int16_t value)                  { Patch2Byte(0x00, value); }
void EquipParamProtector::DefenseThrust(int16_t value)                { Patch2Byte(0x00, value); }
void EquipParamProtector::ResistPoison(int16_t value)                 { Patch2Byte(0x00, value); }
void EquipParamProtector::ResistDisease(int16_t value)                { Patch2Byte(0x00, value); }
void EquipParamProtector::ResistBlood(int16_t value)                  { Patch2Byte(0x00, value); }
void EquipParamProtector::ResistCurse(int16_t value)                  { Patch2Byte(0x00, value); }
void EquipParamProtector::ReinforceTypeId(int16_t value)              { Patch2Byte(0x00, value); }
void EquipParamProtector::TrophySGradeId(int16_t value)               { Patch2Byte(0x00, value); }
void EquipParamProtector::ShopLv(int16_t value)                       { Patch2Byte(0x00, value); }
void EquipParamProtector::KnockbackParamId(uint8_t value)             { PatchByte(0x00, value); }
void EquipParamProtector::FlickDamageCutRate(uint8_t value)           { PatchByte(0x00, value); }
void EquipParamProtector::EquipModelCategory(uint8_t value)           { PatchByte(0x00, value); }
void EquipParamProtector::EquipModelGender(uint8_t value)             { PatchByte(0x00, value); }
void EquipParamProtector::ProtectorCategory(uint8_t value)            { PatchByte(0x00, value); }
void EquipParamProtector::DefenseMaterial(uint8_t value)              { PatchByte(0x00, value); }
void EquipParamProtector::DefenseMaterialSfx(uint8_t value)           { PatchByte(0x00, value); }
void EquipParamProtector::PartsDmgType(uint8_t value)                 { PatchByte(0x00, value); }
void EquipParamProtector::DefenseMaterial_Weak(uint8_t value)         { PatchByte(0x00, value); }
void EquipParamProtector::DefenseMaterialSfx_Weak(uint8_t value)      { PatchByte(0x00, value); }
void EquipParamProtector::IsDiscard(uint8_t value)                    { PatchBinary(0x00, value, 0); }
void EquipParamProtector::IsDrop(uint8_t value)                       { PatchBinary(0x00, value, 1); }
void EquipParamProtector::AbsorbtionPhysical(float value)             { PatchFloat(0x00, value); }
void EquipParamProtector::AbsorbtionSlash(float value)                { PatchFloat(0x00, value); }
void EquipParamProtector::AbsorbtionStrike(float value)               { PatchFloat(0x00, value); }
void EquipParamProtector::AbsorbtionThrust(float value)               { PatchFloat(0x00, value); }
void EquipParamProtector::AbsorbtionMagic(float value)                { PatchFloat(0x00, value); }
void EquipParamProtector::AbsorbtionFire(float value)                 { PatchFloat(0x00, value); }
void EquipParamProtector::AbsorbtionThunder(float value)              { PatchFloat(0x00, value); }
void EquipParamProtector::Poise(float value)                          { PatchFloat(0x0000, value); }
void EquipParamProtector::AbsorbtionDark(float value)                 { PatchFloat(0x0000, value); }
void EquipParamProtector::DefenseDark(int16_t value)                  { Patch2Byte(0x0000, value); }
void EquipParamProtector::ShopPrice(int32_t value)                    { Patch4Byte(0x0000, value); }
void EquipParamProtector::ResistFrost(int16_t value)                  { Patch2Byte(0x0000, value); }

SpEffectParam::SpEffectParam(uint32_t id, uintptr_t address)
  : BaseParam(L"SpEffectParam", id, address) { }
void SpEffectParam::IconId(int32_t value)                       { Patch4Byte(0x00, value); }
void SpEffectParam::ConditionHp(float value)                    { PatchFloat(0x00, value); }
void SpEffectParam::EffectEndurance(float value)                { PatchFloat(0x00, value); }
void SpEffectParam::MotionInterval(float value)                 { PatchFloat(0x00, value); }
void SpEffectParam::MaxHpRate(float value)                      { PatchFloat(0x00, value); }
void SpEffectParam::MaxMpRate(float value)                      { PatchFloat(0x00, value); }
void SpEffectParam::MaxStaminaRate(float value)                 { PatchFloat(0x00, value); }
void SpEffectParam::SlashDamageCutRate(float value)             { PatchFloat(0x00, value); }
void SpEffectParam::BlowDamageCutRate(float value)              { PatchFloat(0x00, value); }
void SpEffectParam::ThrustDamageCutRate(float value)            { PatchFloat(0x00, value); }
void SpEffectParam::NeutralDamageCutRate(float value)           { PatchFloat(0x00, value); }
void SpEffectParam::MagicDamageCutRate(float value)             { PatchFloat(0x00, value); }
void SpEffectParam::FireDamageCutRate(float value)              { PatchFloat(0x00, value); }
void SpEffectParam::ThunderDamageCutRate(float value)           { PatchFloat(0x00, value); }
void SpEffectParam::PhysicsAttackRate(float value)              { PatchFloat(0x00, value); }
void SpEffectParam::MagicAttackRate(float value)                { PatchFloat(0x00, value); }
void SpEffectParam::FireAttackRate(float value)                 { PatchFloat(0x00, value); }
void SpEffectParam::ThunderAttackRate(float value)              { PatchFloat(0x00, value); }
void SpEffectParam::PhysicsAttackPowerRate(float value)         { PatchFloat(0x00, value); }
void SpEffectParam::MagicAttackPowerRate(float value)           { PatchFloat(0x00, value); }
void SpEffectParam::FireAttackPowerRate(float value)            { PatchFloat(0x00, value); }
void SpEffectParam::ThunderAttackPowerRate(float value)         { PatchFloat(0x00, value); }
void SpEffectParam::PhysicsAttackPower(int32_t value)           { Patch4Byte(0x00, value); }
void SpEffectParam::MagicAttackPower(int32_t value)             { Patch4Byte(0x00, value); }
void SpEffectParam::FireAttackPower(int32_t value)              { Patch4Byte(0x00, value); }
void SpEffectParam::ThunderAttackPower(int32_t value)           { Patch4Byte(0x00, value); }
void SpEffectParam::PhysicsDiffenceRate(float value)            { PatchFloat(0x00, value); }
void SpEffectParam::MagicDiffenceRate(float value)              { PatchFloat(0x00, value); }
void SpEffectParam::FireDiffenceRate(float value)               { PatchFloat(0x00, value); }
void SpEffectParam::ThunderDiffenceRate(float value)            { PatchFloat(0x00, value); }
void SpEffectParam::PhysicsDiffence(int32_t value)              { Patch4Byte(0x00, value); }
void SpEffectParam::MagicDiffence(int32_t value)                { Patch4Byte(0x00, value); }
void SpEffectParam::FireDiffence(int32_t value)                 { Patch4Byte(0x00, value); }
void SpEffectParam::ThunderDiffence(int32_t value)              { Patch4Byte(0x00, value); }
void SpEffectParam::NoGuardDamageRate(float value)              { PatchFloat(0x00, value); }
void SpEffectParam::VitalSpotChangeRate(float value)            { PatchFloat(0x00, value); }
void SpEffectParam::NormalSpotChangeRate(float value)           { PatchFloat(0x00, value); }
void SpEffectParam::MaxHpChangeRate(float value)                { PatchFloat(0x00, value); }
void SpEffectParam::BehaviorId(int32_t value)                   { Patch4Byte(0x00, value); }
void SpEffectParam::ChangeHpRate(float value)                   { PatchFloat(0x00, value); }
void SpEffectParam::ChangeHpPoint(int32_t value)                { Patch4Byte(0x00, value); }
void SpEffectParam::ChangeMpRate(float value)                   { PatchFloat(0x00, value); }
void SpEffectParam::ChangeMpPoint(int32_t value)                { Patch4Byte(0x00, value); }
void SpEffectParam::MpRecoverChangeSpeed(int32_t value)         { Patch4Byte(0x00, value); }
void SpEffectParam::ChangeStaminaRate(float value)              { PatchFloat(0x00, value); }
void SpEffectParam::ChangeStaminaPoint(int32_t value)           { Patch4Byte(0x00, value); }
void SpEffectParam::StaminaRecoverChangeSpeed(int32_t value)    { Patch4Byte(0x00, value); }
void SpEffectParam::MagicEffectTimeChange(float value)          { PatchFloat(0x00, value); }
void SpEffectParam::InsideDurability(int32_t value)             { Patch4Byte(0x00, value); }
void SpEffectParam::MaxDurability(int32_t value)                { Patch4Byte(0x00, value); }
void SpEffectParam::StaminaAttackRate(float value)              { PatchFloat(0x00, value); }
void SpEffectParam::PoizonAttackPower(int32_t value)            { Patch4Byte(0x00, value); }
void SpEffectParam::RegistIllness(int32_t value)                { Patch4Byte(0x00, value); }
void SpEffectParam::RegistBlood(int32_t value)                  { Patch4Byte(0x00, value); }
void SpEffectParam::RegistCurse(int32_t value)                  { Patch4Byte(0x00, value); }
void SpEffectParam::FallDamageRate(float value)                 { PatchFloat(0x00, value); }
void SpEffectParam::SoulRate(float value)                       { PatchFloat(0x00, value); }
void SpEffectParam::EquipWeightChangeRate(float value)          { PatchFloat(0x00, value); }
void SpEffectParam::AllItemWeightChangeRate(float value)        { PatchFloat(0x00, value); }
void SpEffectParam::Soul(int32_t value)                         { Patch4Byte(0x00, value); }
void SpEffectParam::AnimIdOffset(int32_t value)                 { Patch4Byte(0x00, value); }
void SpEffectParam::HaveSoulRate(float value)                   { PatchFloat(0x00, value); }
void SpEffectParam::TargetPriority(float value)                 { PatchFloat(0x00, value); }
void SpEffectParam::SightSearchEnemyCut(int32_t value)          { Patch4Byte(0x00, value); }
void SpEffectParam::HearingSearchEnemyCut(float value)          { PatchFloat(0x0000, value); }
void SpEffectParam::GrabityRate(float value)                    { PatchFloat(0x0000, value); }
void SpEffectParam::RegistPoizonChangeRate(float value)         { PatchFloat(0x0000, value); }
void SpEffectParam::RegistIllnessChangeRate(float value)        { PatchFloat(0x0000, value); }
void SpEffectParam::RegistBloodChangeRate(float value)          { PatchFloat(0x0000, value); }
void SpEffectParam::RegistCurseChangeRate(float value)          { PatchFloat(0x0000, value); }
void SpEffectParam::SoulStealRate(float value)                  { PatchFloat(0x0000, value); }
void SpEffectParam::LifeReductionRate(float value)              { PatchFloat(0x0000, value); }
void SpEffectParam::HpRecoverRate(float value)                  { PatchFloat(0x0000, value); }
void SpEffectParam::ReplaceSpEffectId(int32_t value)            { Patch4Byte(0x0000, value); }
void SpEffectParam::CycleOccurrenceSpEffectId(int32_t value)    { Patch4Byte(0x0000, value); }
void SpEffectParam::AtkOccurence(int32_t value)                 { Patch4Byte(0x0000, value); }
void SpEffectParam::GuardDefFlickPowerRate(float value)         { PatchFloat(0x0000, value); }
void SpEffectParam::GuardStaminaCutRate(float value)            { PatchFloat(0x0000, value); }
void SpEffectParam::RayCastPassedTime(int16_t value)            { Patch2Byte(0x0000, value); }
void SpEffectParam::ChangeSuperArmorPoint(int16_t value)        { Patch2Byte(0x0000, value); }
void SpEffectParam::BowDistRate(int16_t value)                  { Patch2Byte(0x0000, value); }
void SpEffectParam::SpCategory(int16_t value)                   { Patch2Byte(0x0000, value); }
void SpEffectParam::CategoryPriority(uint8_t value)             { PatchByte(0x0000, value); }
void SpEffectParam::SaveCategory(uint8_t value)                 { PatchByte(0x0000, value); }
void SpEffectParam::ChangeMagicSlot(uint8_t value)              { PatchByte(0x0000, value); }
void SpEffectParam::ChangeMiracleSlot(uint8_t value)            { PatchByte(0x0000, value); }
void SpEffectParam::HeroPointDamage(uint8_t value)              { PatchByte(0x0000, value); }
void SpEffectParam::DefFlickPower(uint8_t value)                { PatchByte(0x0000, value); }
void SpEffectParam::FlickDamageCutRate(uint8_t value)           { PatchByte(0x0000, value); }
void SpEffectParam::BloodDamageRate(uint8_t value)              { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_None(uint8_t value)                   { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_S(uint8_t value)                      { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_M(uint8_t value)                      { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_L(uint8_t value)                      { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_BlowM(uint8_t value)                  { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_Push(uint8_t value)                   { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_Strike(uint8_t value)                 { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_BlowS(uint8_t value)                  { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_Min(uint8_t value)                    { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_Uppercut(uint8_t value)               { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_BlowLL(uint8_t value)                 { PatchByte(0x0000, value); }
void SpEffectParam::DmgLv_Breath(uint8_t value)                 { PatchByte(0x0000, value); }
void SpEffectParam::AtkAttribute(uint8_t value)                 { PatchByte(0x0000, value); }
void SpEffectParam::SpAttribute(uint8_t value)                  { PatchByte(0x0000, value); }
void SpEffectParam::StateInfo(int16_t value)                    { Patch2Byte(0x0000, value); }
void SpEffectParam::WepParamChange(uint8_t value)               { PatchByte(0x0000, value); }
void SpEffectParam::MoveType(uint8_t value)                     { PatchByte(0x0000, value); }
void SpEffectParam::LifeReductionType(uint8_t value)            { PatchByte(0x0000, value); }
void SpEffectParam::ThrowCondition(uint8_t value)               { PatchByte(0x0000, value); }
void SpEffectParam::AddBehaviorJudgeId_condition(uint8_t value) { PatchByte(0x0000, value); }
void SpEffectParam::AddBehaviorJudgeId_add(uint8_t value)       { PatchByte(0x0000, value); }
void SpEffectParam::TargetSelf(uint8_t value)                   { PatchBinary(0x0000, value, 0); }
void SpEffectParam::TargetFriend(uint8_t value)                 { PatchBinary(0x0000, value, 1); }
void SpEffectParam::TargetEnemy(uint8_t value)                  { PatchBinary(0x0000, value, 2); }
void SpEffectParam::TargetPlayer(uint8_t value)                 { PatchBinary(0x0000, value, 3); }
void SpEffectParam::TargetAI(uint8_t value)                     { PatchBinary(0x0000, value, 4); }
void SpEffectParam::TargetLive(uint8_t value)                   { PatchBinary(0x0000, value, 5); }
void SpEffectParam::TargetGhost(uint8_t value)                  { PatchBinary(0x0000, value, 6); }
void SpEffectParam::TargetWhiteGhost(uint8_t value)             { PatchBinary(0x0000, value, 7); }
void SpEffectParam::TargetBlackGhost(uint8_t value)             { PatchBinary(0x0000, value, 0); }
void SpEffectParam::TargetAttacker(uint8_t value)               { PatchBinary(0x0000, value, 1); }
void SpEffectParam::DispIconNonactive(uint8_t value)            { PatchBinary(0x0000, value, 2); }
void SpEffectParam::UseSpEffectEffect(uint8_t value)            { PatchBinary(0x0000, value, 3); }
void SpEffectParam::BAdjustMagicAblity(uint8_t value)           { PatchBinary(0x0000, value, 4); }
void SpEffectParam::BAdjustFaithAblity(uint8_t value)           { PatchBinary(0x0000, value, 5); }
void SpEffectParam::BGameClearBonus(uint8_t value)              { PatchBinary(0x0000, value, 6); }
void SpEffectParam::MagParamChange(uint8_t value)               { PatchBinary(0x0000, value, 7); }
void SpEffectParam::MiracleParamChange(uint8_t value)           { PatchBinary(0x0000, value, 0); }
void SpEffectParam::ClearSoul(uint8_t value)                    { PatchBinary(0x0000, value, 1); }
void SpEffectParam::RequestSOS(uint8_t value)                   { PatchBinary(0x0000, value, 2); }
void SpEffectParam::RequestBlackSOS(uint8_t value)              { PatchBinary(0x0000, value, 3); }
void SpEffectParam::RequestForceJoinBlackSOS(uint8_t value)     { PatchBinary(0x0000, value, 4); }
void SpEffectParam::RequestKickSession(uint8_t value)           { PatchBinary(0x0000, value, 5); }
void SpEffectParam::RequestLeaveSession(uint8_t value)          { PatchBinary(0x0000, value, 6); }
void SpEffectParam::RequestNpcInveda(uint8_t value)             { PatchBinary(0x0000, value, 7); }
void SpEffectParam::NoDead(uint8_t value)                       { PatchBinary(0x0000, value, 0); }
void SpEffectParam::BCurrHPIndependeMaxHP(uint8_t value)        { PatchBinary(0x0000, value, 1); }
void SpEffectParam::CorrosionIgnore(uint8_t value)              { PatchBinary(0x0000, value, 2); }
void SpEffectParam::SightSearchCutIgnore(uint8_t value)         { PatchBinary(0x0000, value, 3); }
void SpEffectParam::HearingSearchCutIgnore(uint8_t value)       { PatchBinary(0x0000, value, 4); }
void SpEffectParam::AntiMagicIgnore(uint8_t value)              { PatchBinary(0x0000, value, 5); }
void SpEffectParam::FakeTargetIgnore(uint8_t value)             { PatchBinary(0x0000, value, 6); }
void SpEffectParam::FakeTargetIgnoreUndead(uint8_t value)       { PatchBinary(0x0000, value, 7); }
void SpEffectParam::FakeTargetIgnoreAnimal(uint8_t value)       { PatchBinary(0x0000, value, 0); }
void SpEffectParam::GrabityIgnore(uint8_t value)                { PatchBinary(0x0000, value, 1); }
void SpEffectParam::DisablePoison(uint8_t value)                { PatchBinary(0x0000, value, 2); }
void SpEffectParam::DisableDisease(uint8_t value)               { PatchBinary(0x0000, value, 3); }
void SpEffectParam::DisableBlood(uint8_t value)                 { PatchBinary(0x0000, value, 4); }
void SpEffectParam::DisableCurse(uint8_t value)                 { PatchBinary(0x0000, value, 5); }
void SpEffectParam::EnableCharm(uint8_t value)                  { PatchBinary(0x0000, value, 6); }
void SpEffectParam::EnableLifeTime(uint8_t value)               { PatchBinary(0x0000, value, 7); }
void SpEffectParam::HasTarget(uint8_t value)                    { PatchBinary(0x0000, value, 0); }
void SpEffectParam::IsFireDamageCancel(uint8_t value)           { PatchBinary(0x0000, value, 1); }
void SpEffectParam::IsExtendSpEffectLife(uint8_t value)         { PatchBinary(0x0000, value, 2); }
void SpEffectParam::RequestLeaveColiseumSession(uint8_t value)  { PatchBinary(0x0000, value, 3); }
void SpEffectParam::VowType0(uint8_t value)                     { PatchBinary(0x0000, value, 0); }
void SpEffectParam::VowType1(uint8_t value)                     { PatchBinary(0x0000, value, 1); }
void SpEffectParam::VowType2(uint8_t value)                     { PatchBinary(0x0000, value, 2); }
void SpEffectParam::VowType3(uint8_t value)                     { PatchBinary(0x0000, value, 3); }
void SpEffectParam::VowType4(uint8_t value)                     { PatchBinary(0x0000, value, 4); }
void SpEffectParam::VowType5(uint8_t value)                     { PatchBinary(0x0000, value, 5); }
void SpEffectParam::VowType6(uint8_t value)                     { PatchBinary(0x0000, value, 6); }
void SpEffectParam::VowType7(uint8_t value)                     { PatchBinary(0x0000, value, 7); }
void SpEffectParam::VowType8(uint8_t value)                     { PatchBinary(0x0000, value, 0); }
void SpEffectParam::VowType9(uint8_t value)                     { PatchBinary(0x0000, value, 1); }
void SpEffectParam::VowType10(uint8_t value)                    { PatchBinary(0x0000, value, 2); }
void SpEffectParam::VowType11(uint8_t value)                    { PatchBinary(0x0000, value, 3); }
void SpEffectParam::VowType12(uint8_t value)                    { PatchBinary(0x0000, value, 4); }
void SpEffectParam::VowType13(uint8_t value)                    { PatchBinary(0x0000, value, 5); }
void SpEffectParam::VowType14(uint8_t value)                    { PatchBinary(0x0000, value, 6); }
void SpEffectParam::VowType15(uint8_t value)                    { PatchBinary(0x0000, value, 7); }
void SpEffectParam::RestrictFlags(uint8_t value)                { PatchByte(0x0000, value); }
void SpEffectParam::BehaviorFireFrom(uint8_t value)             { PatchByte(0x0000, value); }
void SpEffectParam::EffectSfx(int32_t value)                    { Patch4Byte(0x0000, value); }
void SpEffectParam::TriggerEffect(int32_t value)                { Patch4Byte(0x0000, value); }
void SpEffectParam::TriggerRequirement(int32_t value)           { Patch4Byte(0x0000, value); }
void SpEffectParam::EffectSfx1(int32_t value)                   { Patch4Byte(0x0000, value); }
void SpEffectParam::RegistFrost(int32_t value)                  { Patch4Byte(0x0000, value); }
void SpEffectParam::DarkDamageCutRate(float value)              { PatchFloat(0x0000, value); }
void SpEffectParam::DarkDiffenceRate(float value)               { PatchFloat(0x0000, value); }
void SpEffectParam::DarkDiffence(float value)                   { PatchFloat(0x0000, value); }
void SpEffectParam::DarkAttackPowerRate(float value)            { PatchFloat(0x0000, value); }
void SpEffectParam::DarkAttackPower(int32_t value)              { Patch4Byte(0x0000, value); }
void SpEffectParam::ItemDiscovery(float value)                  { PatchFloat(0x0000, value); }
void SpEffectParam::PvpAbsorbtionPhys(float value)              { PatchFloat(0x0000, value); }
void SpEffectParam::PvpAbsorbtionMag(float value)               { PatchFloat(0x0000, value); }
void SpEffectParam::PvpAbsorbtionFire(float value)              { PatchFloat(0x0000, value); }
void SpEffectParam::PvpAbsorbtionThun(float value)              { PatchFloat(0x0000, value); }
void SpEffectParam::PvpAbsorbtionDark(float value)              { PatchFloat(0x0000, value); }
void SpEffectParam::PveAbsorbtionPhys(float value)              { PatchFloat(0x0000, value); }
void SpEffectParam::PveAbsorbtionMag(float value)               { PatchFloat(0x0000, value); }
void SpEffectParam::PveAbsorbtionFire(float value)              { PatchFloat(0x0000, value); }
void SpEffectParam::PveAbsorbtionThun(float value)              { PatchFloat(0x0000, value); }
void SpEffectParam::PveAbsorbtionDark(float value)              { PatchFloat(0x0000, value); }
void SpEffectParam::PvpAttackPhys(float value)                  { PatchFloat(0x0000, value); }
void SpEffectParam::PvpAttackMag(float value)                   { PatchFloat(0x0000, value); }
void SpEffectParam::PvpAttackFire(float value)                  { PatchFloat(0x0000, value); }
void SpEffectParam::PvpAttackThun(float value)                  { PatchFloat(0x0000, value); }
void SpEffectParam::PvpAttackDark(float value)                  { PatchFloat(0x0000, value); }
void SpEffectParam::RegistFrostChange(int32_t value)            { Patch4Byte(0x0000, value); }
void SpEffectParam::PyroParamChange(uint8_t value)              { PatchBinary(0x0000, value, 0); }
void SpEffectParam::CastDexterity(uint8_t value)                { PatchByte(0x0000, value); }
void SpEffectParam::MagicMpCost(float value)                    { PatchFloat(0x0000, value); }
void SpEffectParam::PyroMpCost(float value)                     { PatchFloat(0x0000, value); }
void SpEffectParam::MiracleMpCost(float value)                  { PatchFloat(0x0000, value); }
void SpEffectParam::EstusHpRate(int32_t value)                  { Patch4Byte(0x0000, value); }
void SpEffectParam::EstusHpPoint(int32_t value)                 { Patch4Byte(0x0000, value); }
void SpEffectParam::EstusMpRate(int32_t value)                  { Patch4Byte(0x0000, value); }
void SpEffectParam::EtsusMpPoint(int32_t value)                 { Patch4Byte(0x0000, value); }
void SpEffectParam::EstusMult(float value)                      { PatchFloat(0x0000, value); }
void SpEffectParam::AshenMult(float value)                      { PatchFloat(0x0000, value); }
void SpEffectParam::Vigor(uint8_t value)                        { PatchByte(0x0000, value); }
void SpEffectParam::Attunement(uint8_t value)                   { PatchByte(0x0000, value); }
void SpEffectParam::Endurance(uint8_t value)                    { PatchByte(0x0000, value); }
void SpEffectParam::Vitality(uint8_t value)                     { PatchByte(0x0000, value); }
void SpEffectParam::Strength(uint8_t value)                     { PatchByte(0x0000, value); }
void SpEffectParam::Dexterity(uint8_t value)                    { PatchByte(0x0000, value); }
void SpEffectParam::Intelligence(uint8_t value)                 { PatchByte(0x0000, value); }
void SpEffectParam::Faith(uint8_t value)                        { PatchByte(0x0000, value); }
void SpEffectParam::Luck(uint8_t value)                         { PatchByte(0x0000, value); }
void SpEffectParam::VigorBuff(uint8_t value)                    { PatchByte(0x0000, value); }
void SpEffectParam::AttunementBuff(uint8_t value)               { PatchByte(0x0000, value); }
void SpEffectParam::EnduranceBuff(uint8_t value)                { PatchByte(0x0000, value); }
void SpEffectParam::VitalityBuff(uint8_t value)                 { PatchByte(0x0000, value); }
void SpEffectParam::StrenghtBuff(uint8_t value)                 { PatchByte(0x0000, value); }
void SpEffectParam::DextrerityBuff(uint8_t value)               { PatchByte(0x0000, value); }
void SpEffectParam::IntelligenceBuff(uint8_t value)             { PatchByte(0x0000, value); }
void SpEffectParam::FaithBuff(uint8_t value)                    { PatchByte(0x0000, value); }
void SpEffectParam::LuckBuff(uint8_t value)                     { PatchByte(0x0000, value); }

SpEffectVfxParam::SpEffectVfxParam(uint32_t id, uintptr_t address)
  : BaseParam(L"SpEffectVfxParam", id, address) { }
void SpEffectVfxParam::MidstSfxID(int32_t value)                     { Patch4Byte(0x00, value); }
void SpEffectVfxParam::MidstSeID(int32_t value)                      { Patch4Byte(0x00, value); }
void SpEffectVfxParam::InitSfxID(int32_t value)                      { Patch4Byte(0x00, value); }
void SpEffectVfxParam::InitSeID(int32_t value)                       { Patch4Byte(0x00, value); }
void SpEffectVfxParam::FinishSfxID(int32_t value)                    { Patch4Byte(0x00, value); }
void SpEffectVfxParam::FinishSeID(int32_t value)                     { Patch4Byte(0x00, value); }
void SpEffectVfxParam::CamouflageBeginDist(float value)              { PatchFloat(0x00, value); }
void SpEffectVfxParam::CamouflageEndDist(float value)                { PatchFloat(0x00, value); }
void SpEffectVfxParam::TransformProtectorID(int32_t value)           { Patch4Byte(0x00, value); }
void SpEffectVfxParam::MidstDmyID(int16_t value)                     { Patch2Byte(0x00, value); }
void SpEffectVfxParam::InitDmyID(int16_t value)                      { Patch2Byte(0x00, value); }
void SpEffectVfxParam::FinishDmyID(int16_t value)                    { Patch2Byte(0x00, value); }
void SpEffectVfxParam::EffectType(uint8_t value)                     { PatchByte(0x00, value); }
void SpEffectVfxParam::SoulParamIDForWepEnchant(uint8_t value)       { PatchByte(0x00, value); }
void SpEffectVfxParam::PlayCategory(uint8_t value)                   { PatchByte(0x00, value); }
void SpEffectVfxParam::PlayPriority(uint8_t value)                   { PatchByte(0x00, value); }
void SpEffectVfxParam::ExistEffectForLarge(uint8_t value)            { PatchBinary(0x00, value, 0); }
void SpEffectVfxParam::ExistEffectForSoul(uint8_t value)             { PatchBinary(0x00, value, 1); }
void SpEffectVfxParam::EffectInvisibleAtCamouflage(uint8_t value)    { PatchBinary(0x00, value, 2); }
void SpEffectVfxParam::UseCamouflage(uint8_t value)                  { PatchBinary(0x00, value, 3); }
void SpEffectVfxParam::InvisibleAtFriendCamouflage(uint8_t value)    { PatchBinary(0x00, value, 4); }
void SpEffectVfxParam::AddMapAreaBlock(uint8_t value)                { PatchBinary(0x00, value, 5); }
void SpEffectVfxParam::HalfCamouflage(uint8_t value)                 { PatchBinary(0x00, value, 6); }
void SpEffectVfxParam::IsFullBodyTransformProtectorID(uint8_t value) { PatchBinary(0x00, value, 7); }
void SpEffectVfxParam::IsInvisibleWeapon(uint8_t value)              { PatchBinary(0x00, value, 0); }
void SpEffectVfxParam::IsSilence(uint8_t value)                      { PatchBinary(0x00, value, 1); }

EquipParamAccessory::EquipParamAccessory(uint32_t id, uintptr_t address)
  : BaseParam(L"EquipParamAccessory", id, address) { }
void EquipParamAccessory::RefId1(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamAccessory::SfxVariation(int32_t value)       { Patch4Byte(0x00, value); }
void EquipParamAccessory::Weight(float value)               { PatchFloat(0x00, value); }
void EquipParamAccessory::BehaviorId(int32_t value)         { Patch4Byte(0x00, value); }
void EquipParamAccessory::BasicPrice(int32_t value)         { Patch4Byte(0x00, value); }
void EquipParamAccessory::SellValue(int32_t value)          { Patch4Byte(0x00, value); }
void EquipParamAccessory::SortId(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamAccessory::QwcId(int32_t value)              { Patch4Byte(0x00, value); }
void EquipParamAccessory::EquipModelId(int16_t value)       { Patch2Byte(0x00, value); }
void EquipParamAccessory::IconId(int16_t value)             { Patch2Byte(0x00, value); }
void EquipParamAccessory::ShopLv(int16_t value)             { Patch2Byte(0x00, value); }
void EquipParamAccessory::TrophySGradeId(int16_t value)     { Patch2Byte(0x00, value); }
void EquipParamAccessory::TrophySeqId(int16_t value)        { Patch2Byte(0x00, value); }
void EquipParamAccessory::EquipModelCategory(uint8_t value) { PatchByte(0x00, value); }
void EquipParamAccessory::EquipModelGender(uint8_t value)   { PatchByte(0x00, value); }
void EquipParamAccessory::AccessoryCategory(uint8_t value)  { PatchByte(0x00, value); }
void EquipParamAccessory::RefCategory(uint8_t value)        { PatchByte(0x00, value); }
void EquipParamAccessory::SpEffectCategory(uint8_t value)   { PatchByte(0x00, value); }
void EquipParamAccessory::IsDiscard(uint8_t value)          { PatchBinary(0x00, value, 3); }
void EquipParamAccessory::IsDrop(uint8_t value)             { PatchBinary(0x00, value, 4); }
void EquipParamAccessory::Covenant(uint8_t value)           { PatchByte(0x00, value); }
void EquipParamAccessory::RefId2(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamAccessory::RefId3(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamAccessory::RefId4(int32_t value)             { Patch4Byte(0x00, value); }
void EquipParamAccessory::RefId6(int32_t value)             { Patch4Byte(0x00, value); }

BonfireWarpParam::BonfireWarpParam(uint32_t id, uintptr_t address)
  : BaseParam(L"BonfireWarpParam", id, address) {  }

NetworkParam::NetworkParam(uint32_t id, uintptr_t address)
  : BaseParam(L"NetworkParam", id, address) {  }
void NetworkParam::AbyssMultiplayLimit(uint8_t value)                    { PatchByte(0x0000, value); }
void NetworkParam::AllAreaSearchRate_BellGuard(uint8_t value)            { PatchByte(0x0000, value); }
void NetworkParam::AllAreaSearchRate_CoopBlue(uint8_t value)             { PatchByte(0x0000, value); }
void NetworkParam::AllAreaSearchRate_VsBlue(uint8_t value)               { PatchByte(0x0000, value); }
void NetworkParam::AvatarMatchSearchMax(int32_t value)                   { Patch4Byte(0x0000, value); }
void NetworkParam::BasicExclusiveHeight(float value)                     { PatchFloat(0x00, value); }
void NetworkParam::BasicExclusiveRange(float value)                      { PatchFloat(0x00, value); }
void NetworkParam::BattleRoyalMatchSearchMax(int32_t value)              { Patch4Byte(0x0000, value); }
void NetworkParam::BattleRoyalMatchSearchMin(int32_t value)              { Patch4Byte(0x0000, value); }
void NetworkParam::BlackKeywordLimitTimeScale(float value)               { PatchFloat(0x00, value); }
void NetworkParam::BloodMessageDisplayMax(uint8_t value)                 { PatchByte(0x0000, value); }
void NetworkParam::BloodMessageEvalHealRate(uint8_t value)               { PatchByte(0x0000, value); }
void NetworkParam::BloodStainDisplayMax(uint8_t value)                   { PatchByte(0x0000, value); }
void NetworkParam::BreakInRequestIntervalTimeSec(float value)            { PatchFloat(0x00, value); }
void NetworkParam::BreakInRequestTimeOutSec(float value)                 { PatchFloat(0x00, value); }
void NetworkParam::CellGroupBottomRange(int32_t value)                   { Patch4Byte(0x0000, value); }
void NetworkParam::CellGroupHorizontalRange(int32_t value)               { Patch4Byte(0x0000, value); }
void NetworkParam::CellGroupTopRange(int32_t value)                      { Patch4Byte(0x0000, value); }
void NetworkParam::DarkPhantomLimitBoostScale(float value)               { PatchFloat(0x0000, value); }
void NetworkParam::DarkPhantomLimitBoostTime(float value)                { PatchFloat(0x0000, value); }
void NetworkParam::DeadingGhostStartPosThreshold(float value)            { PatchFloat(0x00, value); }
void NetworkParam::DistanceOfBeginRecordVersus(float value)              { PatchFloat(0x0000, value); }
void NetworkParam::DistanceOfEndRecordVersus(float value)                { PatchFloat(0x0000, value); }
void NetworkParam::DoorInvalidPlayAreaExtents(float value)               { PatchFloat(0x0000, value); }
void NetworkParam::DownloadEvaluationSpan(float value)                   { PatchFloat(0x00, value); }
void NetworkParam::DownloadSpan(float value)                             { PatchFloat(0x0000, value); }
void NetworkParam::DragonKeywordLimitTimeScale(float value)              { PatchFloat(0x00, value); }
void NetworkParam::GuestPlayerNoTimeOutTime(float value)                 { PatchFloat(0x0000, value); }
void NetworkParam::GuestUpdateTime(float value)                          { PatchFloat(0x0000, value); }
void NetworkParam::HostPlayerNoTimeOutTime(float value)                  { PatchFloat(0x0000, value); }
void NetworkParam::HostRegisterUpdateTime(float value)                   { PatchFloat(0x0000, value); }
void NetworkParam::KeyGuideHeightPlayer(float value)                     { PatchFloat(0x00, value); }
void NetworkParam::KeyGuideRange(float value)                            { PatchFloat(0x00, value); }
void NetworkParam::KeyGuideRangePlayer(float value)                      { PatchFloat(0x00, value); }
void NetworkParam::MaxBellGuardSummonCount(int32_t value)                { Patch4Byte(0x0000, value); }
void NetworkParam::MaxBonfireGhostValidRange(float value)                { PatchFloat(0x0000, value); }
void NetworkParam::MaxBreakInTargetListCount(int32_t value)              { Patch4Byte(0x00, value); }
void NetworkParam::MaxCoopBlueSummonCount(int32_t value)                 { Patch4Byte(0x0000, value); }
void NetworkParam::MaxGhostTotalCount(int32_t value)                     { Patch4Byte(0x0000, value); }
void NetworkParam::MaxReadSignCount(int32_t value)                       { Patch4Byte(0x00, value); }
void NetworkParam::MaxReplayIntervalTime(float value)                    { PatchFloat(0x0000, value); }
void NetworkParam::MaxSignCellCount(int32_t value)                       { Patch4Byte(0x00, value); }
void NetworkParam::MaxSignPosCorrectionRange(float value)                { PatchFloat(0x00, value); }
void NetworkParam::MaxSignTotalCount(int32_t value)                      { Patch4Byte(0x00, value); }
void NetworkParam::MaxVisitListCount(int32_t value)                      { Patch4Byte(0x0000, value); }
void NetworkParam::MaxWriteSignCount(int32_t value)                      { Patch4Byte(0x00, value); }
void NetworkParam::MinBonfireGhostValidRange(float value)                { PatchFloat(0x0000, value); }
void NetworkParam::MinReplayIntervalTime(float value)                    { PatchFloat(0x0000, value); }
void NetworkParam::MinSmallPhantomLimitTimeScale(float value)            { PatchFloat(0x00, value); }
void NetworkParam::MinWhitePhantomLimitTimeScale(float value)            { PatchFloat(0x00, value); }
void NetworkParam::MultiplayDisableLifeTime(float value)                 { PatchFloat(0x0000, value); }
void NetworkParam::PenaltyForgiveItemLimitTime(float value)              { PatchFloat(0x0000, value); }
void NetworkParam::PenaltyPointBeginPenalize(int16_t value)              { Patch2Byte(0x0000, value); }
void NetworkParam::PenaltyPointLanDisconnect(int16_t value)              { Patch2Byte(0x0000, value); }
void NetworkParam::PenaltyPointReboot(int16_t value)                     { Patch2Byte(0x0000, value); }
void NetworkParam::PenaltyPointSignout(int16_t value)                    { Patch2Byte(0x0000, value); }
void NetworkParam::PhantomReturnDelayTime(uint8_t value)                 { PatchByte(0x0000, value); }
void NetworkParam::PhantomWarpMinimumTime(uint8_t value)                 { PatchByte(0x0000, value); }
void NetworkParam::PreviewChrWaitingTime(float value)                    { PatchFloat(0x00, value); }
void NetworkParam::RecordDeadingGhostMinTime(float value)                { PatchFloat(0x0000, value); }
void NetworkParam::RecordDeadingGhostTotalTime(float value)              { PatchFloat(0x0000, value); }
void NetworkParam::RecordWanderingGhostMinTime(float value)              { PatchFloat(0x0000, value); }
void NetworkParam::RecordWanderingGhostTime(float value)                 { PatchFloat(0x0000, value); }
void NetworkParam::ReloadGhostCellCount(int32_t value)                   { Patch4Byte(0x0000, value); }
void NetworkParam::ReloadGhostIntervalTime(float value)                  { PatchFloat(0x0000, value); }
void NetworkParam::ReloadGhostTotalCount(int32_t value)                  { Patch4Byte(0x0000, value); }
void NetworkParam::ReloadNewSignCellCount(int32_t value)                 { Patch4Byte(0x00, value); }
void NetworkParam::ReloadRandomSignCellCount(int32_t value)              { Patch4Byte(0x00, value); }
void NetworkParam::ReloadSearch_BellGuard_Max(float value)               { PatchFloat(0x0000, value); }
void NetworkParam::ReloadSearch_BellGuard_Min(float value)               { PatchFloat(0x0000, value); }
void NetworkParam::ReloadSearch_CoopBlue_Max(float value)                { PatchFloat(0x0000, value); }
void NetworkParam::ReloadSearch_CoopBlue_Min(float value)                { PatchFloat(0x0000, value); }
void NetworkParam::ReloadSearch_RatKing_Max(float value)                 { PatchFloat(0x0000, value); }
void NetworkParam::ReloadSearch_RatKing_Min(float value)                 { PatchFloat(0x0000, value); }
void NetworkParam::ReloadSignCellCount(int32_t value)                    { Patch4Byte(0x00, value); }
void NetworkParam::ReloadSignIntervalTime(float value)                   { PatchFloat(0x00, value); }
void NetworkParam::ReloadSignIntervalTime1(float value)                  { PatchFloat(0x00, value); }
void NetworkParam::ReloadSignIntervalTime2(float value)                  { PatchFloat(0x00, value); }
void NetworkParam::ReloadSignTotalCount(int32_t value)                   { Patch4Byte(0x00, value); }
void NetworkParam::ReloadVisitListCoolTime(float value)                  { PatchFloat(0x0000, value); }
void NetworkParam::ReplayBonfireGhostTime(float value)                   { PatchFloat(0x0000, value); }
void NetworkParam::ReplayBonfireModeRange(float value)                   { PatchFloat(0x0000, value); }
void NetworkParam::ReplayBonfirePhantomParamId(int32_t value)            { Patch4Byte(0x0000, value); }
void NetworkParam::ReplayBonfirePhantomParamIdForCodename(int32_t value) { Patch4Byte(0x0000, value); }
void NetworkParam::ReplayGhostRangeOnView(float value)                   { PatchFloat(0x0000, value); }
void NetworkParam::ReplayGhostRangeOutView(float value)                  { PatchFloat(0x0000, value); }
void NetworkParam::RequestSearchQuickMatchLimit(int32_t value)           { Patch4Byte(0x0000, value); }
void NetworkParam::SignDisplayMax(uint8_t value)                         { PatchByte(0x0000, value); }
void NetworkParam::SignDownloadSpan(float value)                         { PatchFloat(0x00, value); }
void NetworkParam::SignPuddleActiveMessageIntervalSec(float value)       { PatchFloat(0x00, value); }
void NetworkParam::SignUpdateSpan(float value)                           { PatchFloat(0x00, value); }
void NetworkParam::SignVisibleRange(float value)                         { PatchFloat(0x00, value); }
void NetworkParam::SingGetMax(int32_t value)                             { Patch4Byte(0x00, value); }
void NetworkParam::SmallGoldSuccessHostRewardId(int32_t value)           { Patch4Byte(0x0000, value); }
void NetworkParam::SmallKeywordLimitTimeScale(float value)               { PatchFloat(0x00, value); }
void NetworkParam::SrttMaxLimit(float value)                             { PatchFloat(0x0000, value); }
void NetworkParam::SrttMeanDeviationLimit(float value)                   { PatchFloat(0x0000, value); }
void NetworkParam::SrttMeanLimit(float value)                            { PatchFloat(0x0000, value); }
void NetworkParam::StatueCreatableDistance(float value)                  { PatchFloat(0x0000, value); }
void NetworkParam::SummonMessageInterval(float value)                    { PatchFloat(0x0000, value); }
void NetworkParam::TerminateTimeoutTime(uint8_t value)                   { PatchByte(0x0000, value); }
void NetworkParam::UpdateBonfireGhostIntervalTime(float value)           { PatchFloat(0x0000, value); }
void NetworkParam::UpdateSignIntervalTime(float value)                   { PatchFloat(0x00, value); }
void NetworkParam::UpdateVersusGhostIntervalTime(float value)            { PatchFloat(0x0000, value); }
void NetworkParam::UpdateWanderGhostIntervalTime(float value)            { PatchFloat(0x0000, value); }
void NetworkParam::VisitorGuestRequestMessageIntervalSec(float value)    { PatchFloat(0x0000, value); }
void NetworkParam::VisitorListMax(int32_t value)                         { Patch4Byte(0x0000, value); }
void NetworkParam::WanderGhostIntervalLifeTime(float value)              { PatchFloat(0x0000, value); }
void NetworkParam::WhiteKeywordLimitTimeScale(float value)               { PatchFloat(0x00, value); }
void NetworkParam::YellowMonkDownloadSpan(float value)                   { PatchFloat(0x0000, value); }
void NetworkParam::YellowMonkOverallFlowTimeOutTime(float value)         { PatchFloat(0x0000, value); }

PlayRegionParam::PlayRegionParam(uint32_t id, uintptr_t address)
  : BaseParam(L"PlayRegionParam", id, address) {  }
void PlayRegionParam::MultiPlayZoneId(int32_t value)                { Patch4Byte(0x00, value); }
void PlayRegionParam::MultiPlayStartLimitEventFlagId(int32_t value) { Patch4Byte(0x00, value); }
void PlayRegionParam::OtherDisableDistance(float value)             { PatchFloat(0x00, value); }
void PlayRegionParam::PcPositionSaveLimitEventFlagId(int32_t value) { Patch4Byte(0x00, value); }
void PlayRegionParam::MultiPlayHostLimitEventFlagId(int32_t value)  { Patch4Byte(0x00, value); }
void PlayRegionParam::DisolvedEventFlag(int16_t value)              { Patch2Byte(0x00, value); }
void PlayRegionParam::LoadOfCinder(uint8_t value)                   { PatchByte(0x00, value); }
void PlayRegionParam::IsEnableEvent(uint8_t value)                  { PatchBinary(0x00, value, 0); }
void PlayRegionParam::BonfireEventId0(int32_t value)                { Patch4Byte(0x00, value); }
void PlayRegionParam::BonfireEventId1(int32_t value)                { Patch4Byte(0x00, value); }
void PlayRegionParam::BonfireEventId2(int32_t value)                { Patch4Byte(0x00, value); }
void PlayRegionParam::BonfireEventId3(int32_t value)                { Patch4Byte(0x00, value); }
void PlayRegionParam::BonfireEventId4(int32_t value)                { Patch4Byte(0x00, value); }
void PlayRegionParam::BonfireEventId5(int32_t value)                { Patch4Byte(0x00, value); }
void PlayRegionParam::BonfireEventId6(int32_t value)                { Patch4Byte(0x00, value); }
void PlayRegionParam::BonfireEventId7(int32_t value)                { Patch4Byte(0x00, value); }
void PlayRegionParam::BonfireEventId8(int32_t value)                { Patch4Byte(0x00, value); }
void PlayRegionParam::BonfireEventId9(int32_t value)                { Patch4Byte(0x00, value); }
void PlayRegionParam::EnableBloodMessage(uint8_t value)             { PatchBinary(0x00, value, 1); }
void PlayRegionParam::EnableBloodstain(uint8_t value)               { PatchBinary(0x00, value, 0); }
void PlayRegionParam::EnableGhost(uint8_t value)                    { PatchBinary(0x00, value, 2); }

EquipMtrlSetParam::EquipMtrlSetParam(uint32_t id, uintptr_t address)
  : BaseParam(L"EquipMtrlSetParam", id, address) {  }

LodParam::LodParam(uint32_t id, uintptr_t address)
  : BaseParam(L"LodParam", id, address) {  }
void LodParam::Lv01_BorderDist(float value)   { PatchFloat(0x00, value); }
void LodParam::Lv01_PlayDist(float value)     { PatchFloat(0x00, value); }
void LodParam::Lv12_BorderDist(float value)   { PatchFloat(0x00, value); }
void LodParam::Lv12_PlayDist(float value)     { PatchFloat(0x00, value); }
void LodParam::TextureLod(uint8_t value)      { PatchByte(0x00, value); }
void LodParam::Lv23_BorderDist(float value)   { PatchFloat(0x00, value); }
void LodParam::Lv23_PlayDist(float value)     { PatchFloat(0x00, value); }
void LodParam::Lv34_BorderDist(float value)   { PatchFloat(0x00, value); }
void LodParam::Lv34_PlayDist(float value)     { PatchFloat(0x00, value); }
void LodParam::Lv45_BorderDist(float value)   { PatchFloat(0x00, value); }
void LodParam::Lv45_PlayDist(float value)     { PatchFloat(0x00, value); }
void LodParam::DistanceScaleId(uint8_t value) { PatchByte(0x00, value); }

CeremonyParam::CeremonyParam(uint32_t id, uintptr_t address)
  : BaseParam(L"Ceremony", id, address) {  }
void CeremonyParam::EventLayerID(int32_t value)     { Patch4Byte(0x00, value); }
void CeremonyParam::MapStudioLayerID(int32_t value) { Patch4Byte(0x00, value); }
void CeremonyParam::GparamID_Up(int16_t value)      { Patch2Byte(0x00, value); }
void CeremonyParam::GparamID_Low(int16_t value)     { Patch2Byte(0x00, value); }
void CeremonyParam::PointCloudID(int32_t value)     { Patch4Byte(0x00, value); }
void CeremonyParam::Gl_TextureID(int32_t value)     { Patch4Byte(0x00, value); }
void CeremonyParam::LightGroupID(int32_t value)     { Patch4Byte(0x00, value); }
void CeremonyParam::IsReload(uint8_t value)         { PatchByte(0x00, value); }
void CeremonyParam::IsDisableOnline(uint8_t value)  { PatchByte(0x00, value); }

