#pragma once
#include "Item.h"
#include "WeaponTypeInfo.h"
#include <vector>
#include <map>
class ItemShop
{
private:
	Item currentAvailableItems[4];
	
public:
	enum ShopCategories { Items, Weapons, Potions };
	ItemShop(); 
	void SetItems(const Item items[4]); // Take an array of 4 items
	const Item(&GetItems() const)[4];
	void GenerateItems(int maxValue);
	~ItemShop();
};
