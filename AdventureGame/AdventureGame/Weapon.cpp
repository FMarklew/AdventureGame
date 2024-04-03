#include "Weapon.h"

Weapon::Weapon(int _price, string _name, string _description, int _damage)
	: Item(_price, _name, _description), damage(_damage)
{
	damage = _damage;
}

// destructor
Weapon::~Weapon() {}
