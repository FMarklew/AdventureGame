#pragma once
#include "Item.h"

class Weapon : public Item {
public:
	int damage;
	Weapon();
	Weapon(int _price, string _name, string _description, int _damage);
	std::string to_string() const override;
	~Weapon();
};

