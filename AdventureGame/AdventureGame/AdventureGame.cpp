#include "AdventureGame.h"
using std::cout, std::endl, std::vector;

// TODO: implement adventure generation based on encounter types
inline void GenerateAdventure() {
	int totalNonBossEncounters = 9;
	for (int i = 0; i < totalNonBossEncounters; ++i) {
		
	}
}

int main()
{
	 // setup
	int totalGold = 15;
	int maxItemLevel = 10;
	int health = 100;

	InventorySystem inventory;
	Weapon* basicSword = new Weapon("Simple Sword", "A simple steel blade", 10, 10, 1);
	
	inventory.AddItem(basicSword);
	inventory.EquipWeapon(basicSword);
	inventory.ShowInventory();

	cout << "health: " << health << endl;
	inventory.UsePotion(Health, health);
	cout << "health: " << health << endl;
	Potion* healthPot = new Potion(10, Health, 20);
	inventory.AddItem(healthPot);
	inventory.ShowInventory();
	inventory.UsePotion(Health, health);
	cout << "health: " << health << endl;
	inventory.UsePotion(Health, health);
	inventory.ShowInventory();


	// initial shop options
	/*ItemShop shop = ItemShop();
	Item* item = new Item(10, "Key", "A magical key", true);
	inventory.AddItem(item);
	Weapon* weapon = new Weapon("Enchanted Sword", "A superbly fine blade enchanted by a mage", 15, 20, 1);
	std::array<Item*, 4> items = { item, weapon, nullptr, nullptr };
	shop.SetItems(items);
	shop.PrintItems();*/

	/*Potion p = Potion(Health, 10);
	cout << health << " --> ";
	p.ActivatePotion(&health);
	cout << health;*/

	// generated adventure (riddles/combat/shop/npc)
	//shop.GenerateItems(21);
	//shop.PrintItems();
	
	GenerateAdventure();
	// generated final boss

	// _ _ _ X _ _ _ _ _ _ _ B
	
	return 0;
}
