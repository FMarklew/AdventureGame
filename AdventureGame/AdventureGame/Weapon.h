#pragma once
#include "Item.h"

class Weapon : public Item {
public:
	int damage;
	int range = 1;
	Weapon();
	Weapon(string _name, string _description, int _price, int _damage, int _range);
	std::string to_string() const override;
	~Weapon();
};

