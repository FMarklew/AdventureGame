#pragma once

#include <vector>
#include "Item.h"
#include "Weapon.h"
class InventorySystem {
	std::vector<Item*> currentItems = std::vector<Item*>();
	Weapon* currentWeapon = nullptr;
public:
	InventorySystem();
	bool AddItem(Item* item);
	bool RemoveItem(Item* item);
	void ShowInventory();
	void SetCurrentWeapon(Weapon* item);
	~InventorySystem();
};