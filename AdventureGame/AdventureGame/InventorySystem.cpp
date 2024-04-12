#include "InventorySystem.h"

InventorySystem::InventorySystem() {
	
}

InventorySystem::~InventorySystem() {
	for (Item*& item : currentItems) {
		if (item != nullptr) {
			delete item;
			item = nullptr;  // Set to nullptr after deletion to avoid dangling pointers
		}
	}
	currentItems.clear();
}

bool InventorySystem::AddItem(Item* item)
{
	currentItems.push_back(item);
	return true;
}

bool InventorySystem::RemoveItem(const Item* item) {
	for (auto it = currentItems.begin(); it != currentItems.end(); ++it) {
		if (*it == item) {
			delete* it; // Free the memory
			currentItems.erase(it); // Remove the pointer from the vector
			return true;
		}
	}
	return false;
}

void InventorySystem::EquipWeapon(const Item* weapon) {
	auto it = std::find(currentItems.begin(), currentItems.end(), weapon);
	if (it != currentItems.end()) {
		equippedItemIndex = std::distance(currentItems.begin(), it);
	}
	else {
		std::cout << "Weapon not found in inventory." << std::endl;
		equippedItemIndex = -1;
	}
}

void InventorySystem::ShowInventory() const {
	std::cout << "---INVENTORY-------\n";
	for (size_t i = 0; i < currentItems.size(); ++i) {
		std::cout << "- " << currentItems[i]->to_string();
		if (static_cast<int>(i) == equippedItemIndex) { // Check if the current item is the equipped weapon
			std::cout << " [EQUIPPED]";
		}
		std::cout << "\n";
	}
	std::cout << "--------------------\n";
}

void InventorySystem::UsePotion(const PotionType potType, int& ref) {
	auto it = std::find_if(currentItems.begin(), currentItems.end(),
		[&potType](Item* item) -> bool {
			const Potion* potion = dynamic_cast<const Potion*>(item);
			return potion && potion->GetPotionType() == potType;
		});

	if (it != currentItems.end()) {
		
		const Potion* potion = dynamic_cast<const Potion*>(*it);
		if (potion) {
			ref += potion->GetAdjustmentAmount();
			*it = nullptr; // Set the deleted pointer to nullptr
			currentItems.erase(it);  // Removes the nullptr pointer from the vector
		}
	}
	else {
		std::cout << "Potion not found in inventory." << std::endl;
	}
}