#include "ItemShop.h"

#pragma region Helpers
int GetHighestItemLevel(int maxValue, int baseCost, int costScaling) {
	int maxLevel = 1;
	int currentCost = baseCost;
	if (baseCost > maxValue) return -1;
	while (currentCost + costScaling <= maxValue) {
		currentCost += costScaling;
		maxLevel++;
	}
	return maxLevel+1;
}

#pragma endregion

Weapon* ItemShop::GenerateWeapon(int maxVal)
{
	int randWeaponType = rand() % TOTAL_WEAPON_TYPES;
	WeaponType weapType = static_cast<WeaponType>(randWeaponType);
	WeaponInfo weapInfo = weaponInfo[weapType];
	int highestIlvl = GetHighestItemLevel(maxVal, weapInfo.baseCost, weapInfo.costScaling);
	int randItemLevel = rand() % highestIlvl;
	return new Weapon(GetWeaponTypeName(weapType), "A magic item, ilvl: " + std::to_string(randItemLevel),
		weapInfo.baseCost + (weapInfo.costScaling * (randItemLevel)),
		weapInfo.baseDamage + (weapInfo.damageScaling * (randItemLevel)),
		weapInfo.range);
}

std::string ItemShop::to_string() const
{
	return "I";
}

void ItemShop::OnEncounterStarted() const
{
	std::cout << "Welcome to the shop!";
}

void ItemShop::OnEncounterCompleted() const
{
	std::cout << "Thank you for shopping with us!";
}

ItemShop::ItemShop()
{
	for (Item* item:currentAvailableItems) {
		item = nullptr; // Initialize all pointers to nullptr
	}
}

void ItemShop::SetItems(const std::array<Item*, 4>& items) {
	currentAvailableItems = items; // Direct assignment works because std::array knows its size
	
}

const std::array<Item*, 4>& ItemShop::GetItems() const {
	return currentAvailableItems;
}

void ItemShop::GenerateItems(int maxValue)
{
	int totalCategories = 3;
	srand(time(NULL));
	for (int i = 0; i < std::size(currentAvailableItems); ++i) {
		
		int randomized = rand() % totalCategories; // random category
		//ShopCategories category = static_cast<ShopCategories>(randomized);
		ShopCategories category = Weapons;
		switch (category) {
			case Items:
				break;
			case Weapons:
				currentAvailableItems[i] = GenerateWeapon(maxValue);
				break;
			case Potions:
				break;
			default:
				break;
		}
	}
}

void ItemShop::PrintItems()
{
	std::cout << "---SHOP------------- " << std::endl;
	for (int i = 0; i < currentAvailableItems.size(); ++i) {
		if (currentAvailableItems[i] != nullptr) {
			std::cout << currentAvailableItems[i]->to_string() << std::endl;
		}
	}
	std::cout << "-------------------- " << std::endl;
}

ItemShop::~ItemShop()
{
	for (Item* item : currentAvailableItems) {
		delete item; // Delete each dynamically allocated Item
		item = nullptr;
	}
}