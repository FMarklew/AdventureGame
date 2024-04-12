#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Potion.h"
#include "InventorySystem.h"
class InventorySystem {
private:
    std::vector<Item*> currentItems;
    int equippedItemIndex; // -1 indicates no item is equipped
public:
    InventorySystem();
    ~InventorySystem();

    bool AddItem(Item* item);
    bool RemoveItem(const Item* item); 
    void EquipWeapon(const Item* weapon);
    void ShowInventory() const;
    void UsePotion(const PotionType potType, int& ref);
};