#pragma once
#include "Item.h"
#include "WeaponInfo.h"
#include "Weapon.h"
#include <vector>
#include <map>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <array>
class ItemShop
{
private:
	static const int maxShopItems = 4;
	std::array<Item*, maxShopItems> currentAvailableItems;
	Weapon* GenerateWeapon(int maxVal);
public:
	enum ShopCategories { Items, Weapons, Potions };
	
	std::map<WeaponType, WeaponInfo> weaponInfo {
			{Sword, WeaponInfo(10,2,10,2,1)},
			{Axe, WeaponInfo(18,1,15,1,1)},
			{Spear, WeaponInfo(8,2,10,4,2)},
			{Bow, WeaponInfo(10,1,10,5,5)}
	};

	ItemShop(); 
	void SetItems(const std::array<Item*, 4>& items);
	const std::array<Item*, maxShopItems>& GetItems() const;
	void GenerateItems(int maxValue);
	void PrintItems();
	~ItemShop();
};
