#include "Potion.h"

std::string Potion::to_string() const
{
    return GetPotionTypeName(potionType) + " potion " + "[" + std::to_string(price) + "g]" + " [Amount: " + std::to_string(adjustmentAmount)+ "]";
}

PotionType Potion::GetPotionType() const
{
    return potionType;
}

int Potion::GetAdjustmentAmount() const
{
    return adjustmentAmount;
}

Potion::~Potion()
{
}

Potion::Potion(int _price, PotionType _potionType, int _adjustmentAmount) : Item(_price, "", "", true), potionType(_potionType), adjustmentAmount(_adjustmentAmount)
{
    
}

void Potion::ActivatePotion(int* ref)
{
    *ref += adjustmentAmount;
}
