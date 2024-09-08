#pragma once
#include <vector>
#include <string>

class InventoryItem {
private:
	std::string name;
	std::string category;
	int value;
public:
	InventoryItem(std::string name, std::string category, int value) : name(name), category(category), value(value) {}

	std::string getName() const { return name; }
	std::string getCategory() const { return category; }
	int getValue() const { return value; }
};

class Inventory {
private:
	std::vector<InventoryItem> items;

public:
	void addItem(InventoryItem item)
	{
		items.push_back(item);
	}

	std::vector<InventoryItem> getItems() const { return items; }
};