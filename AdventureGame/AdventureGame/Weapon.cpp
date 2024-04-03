#include "Weapon.h"
Weapon::Weapon(){}
Weapon::Weapon(int _price, string _name, string _description, int _damage)
	: Item(_price, _name, _description), damage(_damage)
{
	damage = _damage;
}
std::string Weapon::to_string() const {
	return Item::to_string() + "[" + std::to_string(damage) + "dmg]";
}
// destructor
Weapon::~Weapon() {}
