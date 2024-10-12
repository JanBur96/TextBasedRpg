#pragma once
#include "InventoryItem.h"
#include <string>
#include <vector>
#include "ItemType.h"
#include <memory>

std::vector<std::unique_ptr<InventoryItem>> itemMapper(std::vector<ItemType>& items);

std::string itemTypeToString(ItemType itemType);