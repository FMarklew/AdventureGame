#include "Item.h"
#include "Weapon.h"
#include "InventorySystem.h"
#include "WeaponTypeInfo.h"
#include <iostream>
#include <vector>
#include <map>
#pragma once

enum WeaponType { Sword, Axe, Spear, Bow };

std::map<WeaponType, WeaponTypeInfo> weaponInfo{
		{Sword, WeaponTypeInfo(10,2,1,10,5)},
		{Axe, WeaponTypeInfo(18,1,1,15,2)},
		{Spear, WeaponTypeInfo(8,2,2,10,6)},
		{Bow, WeaponTypeInfo(10,1,5,10,5)}
};
