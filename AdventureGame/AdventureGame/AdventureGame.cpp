#include "AdventureGame.h"
using std::cout, std::endl, std::vector;

int main()
{
	 // setup
	int totalGold = 15;
	int maxItemLevel = 10;
	InventorySystem inventory;
	Weapon basicSword = Weapon("Simple Sword", "A simple steel blade", 10, 10, 1);
	
	inventory.AddItem(basicSword);
	inventory.EquipWeapon(basicSword);
	inventory.ShowInventory();

	Item* item = new Item(10, "Key", "A magical key", true);
	inventory.AddItem(*item);
	Weapon* weapon = new Weapon("Enchanted Sword", "A superbly fine blade enchanted by a mage", 15, 20, 1);
	inventory.ShowInventory();
	// initial shop options
	ItemShop shop = ItemShop(); 
	std::array<Item*, 4> items = { item, weapon, nullptr, nullptr };
	shop.SetItems(items);

	
	shop.PrintItems();

	// generated adventure (riddles/combat/shop/npc)
	shop.GenerateItems(21);
	shop.PrintItems();

	// generated final boss

	// _ _ _ X _ _ _ _ _ _ _ B
}

