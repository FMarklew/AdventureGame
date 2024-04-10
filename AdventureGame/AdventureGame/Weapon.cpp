#include "Weapon.h"
Weapon::Weapon(){}
Weapon::Weapon(string _name, string _description, int _price, int _damage, int _range)
	: Item(_price, _name, _description), damage(_damage), range(_range)
{

}
std::string Weapon::to_string() const {
	return Item::to_string() + "[DMG: " + std::to_string(damage) + ", RANGE: " + std::to_string(range) + "]";
}
// destructor
Weapon::~Weapon() {}
