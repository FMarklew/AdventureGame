#pragma once

struct WeaponTypeInfo {

public:
	int baseDamage;
	int damageScaling = 0;
	int range = 1;
	int baseCost = 10;
	int costScaling = 5;
	WeaponTypeInfo(int _baseDamage, int _damageScaling, int _range, int _baseCost, int _costScaling) {
		baseDamage = _baseDamage;
		damageScaling = _damageScaling;
		range = _range;
		baseCost = _baseCost;
		costScaling = _costScaling;
	}
};