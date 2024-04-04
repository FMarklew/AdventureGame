#pragma once
#include <string>
using std::string;

class Item
{
public:
	int price;
	string name;
	string description;
	bool allowMultiple;
	Item();
	Item(int _price, string _name, string _description, bool _allowMultiple = false);
	bool operator==(const Item& other) const;
	virtual std::string to_string() const;
	virtual ~Item();
};
