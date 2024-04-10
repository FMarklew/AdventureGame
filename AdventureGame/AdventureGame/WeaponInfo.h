#pragma once


enum WeaponType { Sword, Axe, Spear, Bow, TOTAL_WEAPON_TYPES };
inline string GetWeaponTypeName(WeaponType weapType) {
    switch (weapType) {
    case Sword:
        return "Sword";
    case Axe:
        return "Axe";
    case Spear:
        return "Spear";
    case Bow:
        return "Bow";
    default:
        return "Unknown Weapon";
    }
}
class WeaponInfo {
public:
	int baseDamage;
	int damageScaling;
	int baseCost;
	int costScaling;
	int range;
	WeaponInfo() {}
	WeaponInfo(int _baseDamage, int _damageScaling, int _baseCost, int _costScaling, int _range) : 
		baseDamage (_baseDamage), damageScaling(_damageScaling), baseCost(_baseCost), costScaling(_costScaling), range(_range) {}

};