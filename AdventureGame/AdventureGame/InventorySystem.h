#pragma once

#include <vector>
#include <memory>
#include "Item.h"
#include "Weapon.h"

class InventorySystem {
public:
    InventorySystem();
    ~InventorySystem();

    bool AddItem(const Item& item);
    bool RemoveItem(const Item& item); 
    void EquipWeapon(const Item& weapon);
    void ShowInventory() const;

private:
    std::vector<Item> currentItems;
    int equippedItemIndex; // -1 indicates no item is equipped
};