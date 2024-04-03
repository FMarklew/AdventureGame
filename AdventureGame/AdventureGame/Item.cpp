#include "Item.h"
Item::Item()
{
	name = "";
	price = 0;
	description = "";
	allowMultiple = false;
}

Item::Item(int _price, string _name, string _description, bool _allowMultiple)
	: price(_price), name(_name), description(_description), allowMultiple(_allowMultiple)
{
}

// equality
bool Item::operator==(const Item& other) const {
	return name == other.name &&
		price == other.price &&
		description == other.description;
}

std::string Item::to_string() const
{
	return name + " (" + description + ") [" + std::to_string(price) + "g]";
}

// destructor
Item::~Item()
{
}
