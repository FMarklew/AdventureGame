#include "AdventureGame.h"
using std::cout, std::endl, std::vector;

int main()
{
     // setup
    int totalGold = 15;
    InventorySystem inventory;
    Weapon* basicSword = new Weapon(10, "Simple Sword", "A simple steel blade", 10);
    inventory.AddItem(basicSword);
    inventory.SetCurrentWeapon(basicSword);
    inventory.ShowInventory();

    Item* item = new Item(10, "Key", "A magical key", true);
    inventory.AddItem(item);
    Weapon* weapon = new Weapon(15, "Enchanted Sword", "A superbly fine blade enchanted my a mage", 20);
    
    // initial shop options


    // generated adventure (riddles/combat/shop/npc)


    // generated final boss

    // ___X_______B
}

