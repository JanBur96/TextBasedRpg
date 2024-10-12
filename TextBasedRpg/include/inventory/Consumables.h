#pragma once
#include "InventoryItem.h"
#include "ItemType.h"

class Consumable : public InventoryItem {
protected:
    int potency;
public:
    Consumable(ItemType type, std::string name, int value, int quantity, int potency)
        : InventoryItem(type, name, value, quantity), potency(potency) {}
    ~Consumable() override = default;

    void printItem() override;

    virtual void useItem(Player& player, int index) = 0;
    int getPotency() const { return potency; }
};

class HealthPotion : public Consumable {
public:
    HealthPotion(ItemType type, std::string name, int worth, int quantity, int potency)
        : Consumable(type, name, worth, quantity, potency) {}
    void useItem(Player& player, int index) override;
};

class ManaPotion : public Consumable {
public:
    ManaPotion(ItemType type, std::string name, int worth, int quantity, int potency)
        : Consumable(type, name, worth, quantity, potency) {}
    void useItem(Player& player, int index) override;
};