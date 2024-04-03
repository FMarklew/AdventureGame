#include "AdventureGame.h"
using std::cout, std::endl, std::vector;

int main()
{
    InventorySystem inventory = InventorySystem();
    Item item = Item(10, "Key", "A magical key", true);

    cout << "ITEM: " << item.name << " (" << item.description << ") || PRICE: $" << item.price << endl;

    Weapon weapon = Weapon(15, "Enchanted Sword", "A superbly fine blade enchanted my a mage", 20);

    cout << "WEAPON: " << weapon.name << " (" << weapon.description << ") DAMAGE: " << weapon.damage << " || PRICE: $" << weapon.price << endl;

    inventory.AddItem(weapon);
    inventory.AddItem(item);
    inventory.AddItem(item);
    inventory.ShowInventory();
}

