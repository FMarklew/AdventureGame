#pragma once
#include "Item.h"

enum PotionType {Health, Strength, Speed};
inline string GetPotionTypeName(PotionType weapType) {
    switch (weapType) {
    case Health:
        return "Health";
    case Strength:
        return "Strength";
    case Speed:
        return "Speed";
    default:
        return "Unknown Potion";
    }
}
class Potion : public Item
{
private:
	int adjustmentAmount = 0;
	PotionType potionType;
public:
	Potion(int _price, PotionType _potionType, int _adjustmentAmount);
	void ActivatePotion(int* ref);
	std::string to_string() const override; 
	PotionType GetPotionType() const;
	int GetAdjustmentAmount() const;
	~Potion() override;
};

