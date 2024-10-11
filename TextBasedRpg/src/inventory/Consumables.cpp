#include "inventory/Consumables.h"
#include "player/Player.h"

void Consumable::printItem()
{
	std::cout << "  Name: " << getName() << "\n";
	std::cout << "  Value: " << getValue() << "\n";
	std::cout << "  Quantity: " << getQuantity() << "\n";
	std::cout << "  Potency: " << getPotency() << "\n";
}

void HealthPotion::useItem(Player& player, int index) {
    player.restoreHealth(potency);
	int quantity = getQuantity();
	if (quantity > 1)
	{
		setQuantity(quantity - 1);
	}
	else
	{
		player.getInventory().deleteItem(index - 1);
	}
}

void ManaPotion::useItem(Player& player, int index) {
    player.restoreMana(potency);
}