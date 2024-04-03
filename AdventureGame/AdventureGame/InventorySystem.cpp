#include "InventorySystem.h"
#include <iostream>

InventorySystem::InventorySystem() {

}

InventorySystem::~InventorySystem() {
	for (auto& item : currentItems) {
		delete item;
	}
}

bool InventorySystem::AddItem(Item* item)
{
	// return iterator for found object if any, currentItems.end() otherwise
	//             function to find		iter at start	iter at end			pointer to item		pointer to ref item
	auto foundItem = std::find_if(currentItems.begin(), currentItems.end(), [&item](Item* refItem) {
		return *refItem == item; // Assuming operator== is correctly implemented in Item
		});

	if (foundItem == currentItems.end() || item->allowMultiple) {
		// item not found
		currentItems.push_back(item);
		return true;
	}
	return false;
}

bool InventorySystem::RemoveItem(Item* item)
{
	auto it = std::find_if(currentItems.begin(), currentItems.end(), [&item](const Item* refItem) {
		return *refItem == item;
		});

	if (it != currentItems.end()) {
		currentItems.erase(it); // Erase the found item
		return true;
	}
	return false;
}

void InventorySystem::ShowInventory()
{

	std::cout << "-----Items-----\n";
	for (const auto& item : currentItems) {
		std::cout << "- ";
		if (dynamic_cast<Weapon*>(item) == currentWeapon) { // Check if item is the currentWeapon
			std::cout << "[EQUIPPED] ";
		}
		std::cout << item->to_string() << "\n";
	}
	std::cout << "---------------\n";
}

void InventorySystem::SetCurrentWeapon(Weapon* weapon)
{
	auto foundItem = std::find_if(currentItems.begin(), currentItems.end(), [&weapon](const Item* refItem) {
		return *refItem == weapon;
		});
	if (foundItem != currentItems.end()) {
		currentWeapon = weapon;
	}
}
