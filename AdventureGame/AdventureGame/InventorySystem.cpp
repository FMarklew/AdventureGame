#include "InventorySystem.h"
#include <iostream>

bool InventorySystem::AddItem(Item item)
{
	// return iterator for found object if any, currentItems.end() otherwise
	//             function to find		iter at start	iter at end			pointer to item		pointer to ref item
	auto foundItem = std::find_if(currentItems.begin(), currentItems.end(), [&item](const Item& refItem) {
		return refItem == item;
		});

	if (foundItem == currentItems.end() || item.allowMultiple) {
		// item not found
		currentItems.push_back(item);
		return true;
	}
	return false;
}

bool InventorySystem::RemoveItem(Item item)
{
	auto it = std::find_if(currentItems.begin(), currentItems.end(), [&item](const Item& refItem) {
		return refItem == item;
		});

	if (it != currentItems.end()) {
		currentItems.erase(it); // Erase the found item
		return true;
	}
	return false;
}

void InventorySystem::ShowInventory()
{
	for (auto item = currentItems.begin(); item != currentItems.end(); ++item) {
		std::cout << item->to_string();
		if (item != currentItems.end() - 1) {
			std::cout << ", ";
		}
	}
}
