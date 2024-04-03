#pragma once
#include "Item.h"

class Weapon : public Item {
public:
	int damage;
	Weapon(int _price, string _name, string _description, int _damage);
	~Weapon();
};

