#include "inventory/itemMapper.h"
#include "inventory/InventoryItem.h"
#include "inventory/Consumables.h"
#include "inventory/ItemType.h"
#include "inventory/Collectable.h"
#include <memory>


std::vector<std::unique_ptr<InventoryItem>> itemMapper(std::vector<ItemType>& items)
{
    std::vector<std::unique_ptr<InventoryItem>> inventoryItems;
    for (const auto& item : items)
    {
        switch (item)
        {
            case ItemType::SHealthPotion:
                inventoryItems.push_back(std::make_unique<HealthPotion>(ItemType::SHealthPotion, "Health Potion S", 5, 1, 0));
                break;
            case ItemType::MHealthPotion:
                inventoryItems.push_back(std::make_unique<HealthPotion>(ItemType::MHealthPotion, "Health Potion M", 10, 1, 0));
                break;
            case ItemType::LHealthPotion:
                inventoryItems.push_back(std::make_unique<HealthPotion>(ItemType::LHealthPotion, "Health Potion L", 15, 1, 0));
                break;
            case ItemType::SManaPotion:
                inventoryItems.push_back(std::make_unique<ManaPotion>(ItemType::SManaPotion, "Mana Potion S", 5, 1, 0));
                break;
            case ItemType::MManaPotion:
                inventoryItems.push_back(std::make_unique<ManaPotion>(ItemType::MManaPotion, "Mana Potion M", 10, 1, 0));
                break;
            case ItemType::LManaPotion:
                inventoryItems.push_back(std::make_unique<ManaPotion>(ItemType::LManaPotion, "Mana Potion L", 15, 1, 0));
                break;
            case ItemType::WolfsClaw:
                inventoryItems.push_back(std::make_unique<InventoryItem>(ItemType::WolfsClaw, "Wolf's Claw", 0, 1));
                break;
        default:
            break;
        }
    }
    return inventoryItems;
}

std::string itemTypeToString(ItemType itemType)
{
	switch (itemType)
	{
	case ItemType::SHealthPotion:
		return "Health Potion";
	case ItemType::MHealthPotion:
		return "Health Potion";
	case ItemType::LHealthPotion:
		return "Health Potion";
	case ItemType::SManaPotion:
		return "Mana Potion";
	case ItemType::MManaPotion:
		return "Mana Potion";
	case ItemType::LManaPotion:
		return "Mana Potion";
	case ItemType::WolfsClaw:
		return "Wolf's Claw";
	default:
		return "Unknown";
	}
}