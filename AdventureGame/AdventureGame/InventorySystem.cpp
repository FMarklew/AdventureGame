#include "InventorySystem.h"
#include <algorithm>
#include <iostream>

InventorySystem::InventorySystem() {}

InventorySystem::~InventorySystem() {
    
}

bool InventorySystem::AddItem(const Item& item) {
    currentItems.push_back(item);
    return true;
}

bool InventorySystem::RemoveItem(const Item& item) {
    for (auto it = currentItems.begin(); it != currentItems.end(); ++it) {
        if (*it == item) {
            if (std::distance(currentItems.begin(), it) == equippedItemIndex) {
                equippedItemIndex = -1; // Un-equip if the removed item was equipped
            }
            currentItems.erase(it);
            return true;
        }
    }
    return false;
}

void InventorySystem::EquipWeapon(const Item& weapon) {
    auto it = std::find_if(currentItems.begin(), currentItems.end(),
        [&weapon](const Item& item) { return item == weapon; });
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
        std::cout << "- " << currentItems[i].to_string();
        if (static_cast<int>(i) == equippedItemIndex) { // Check if the current item is the equipped weapon
            std::cout << " [EQUIPPED]";
        }
        std::cout << "\n";
    }
    std::cout << "--------------------\n";
}