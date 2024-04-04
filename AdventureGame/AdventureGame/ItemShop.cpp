#include "ItemShop.h"

ItemShop::ItemShop()
{

}

void ItemShop::SetItems(const Item items[4]) {
    for (int i = 0; i < 4; ++i) {
        currentAvailableItems[i] = items[i]; // Copy each item
    }
}

const Item(&ItemShop::GetItems() const)[4] {
    return currentAvailableItems; // Return a reference to the array
}

void ItemShop::GenerateItems(int maxValue)
{
    for (int i = 0; i < std::size(currentAvailableItems); i++) {

    }
}

ItemShop::~ItemShop()
{
    
}