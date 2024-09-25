#pragma once
#include <vector>
#include <memory>
#include "InventoryItem.h"

class Inventory {
private:
    std::vector<std::unique_ptr<InventoryItem>> items;

public:
    void addItem(std::unique_ptr<InventoryItem> item)
    {
        items.push_back(std::move(item));
    }

    void deleteItem(int index)
	{
		items.erase(items.begin() + index);
	}

    const std::vector<std::unique_ptr<InventoryItem>>& getItems() const { return items; }
};