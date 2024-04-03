#pragma once

#include <vector>
#include "Item.h"
class InventorySystem {
	std::vector<Item> currentItems = std::vector<Item>();
public:
	bool AddItem(Item item);
	bool RemoveItem(Item item);
	void ShowInventory();
};