#include "AdventureGame.h"
#include "ItemShop.h"
using std::cout, std::endl, std::vector;

int main()
{
     // setup
    int totalGold = 15;
    int maxItemLevel = 10;
    InventorySystem inventory;
    Weapon basicSword = Weapon(10, "Simple Sword", "A simple steel blade", 10);
    
    inventory.AddItem(basicSword);
    inventory.EquipWeapon(basicSword);
    inventory.ShowInventory();

    Item item = Item(10, "Key", "A magical key", true);
    inventory.AddItem(item);
    Weapon weapon = Weapon(15, "Enchanted Sword", "A superbly fine blade enchanted by a mage", 20);
    
    // initial shop options
    ItemShop shop = ItemShop(); 
    Item items[4] = { item, weapon, Item(), Item() };
    shop.SetItems(items);

    cout << "---SHOP------------- " << endl;
    for (Item i : shop.GetItems()) {
        if (i.name != "") {
            cout << i.to_string() << endl;
        }
    }
    cout << "-------------------- " << endl;
    // generated adventure (riddles/combat/shop/npc)


    // generated final boss

    // _ _ _ X _ _ _ _ _ _ _ B
}

