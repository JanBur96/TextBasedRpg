#pragma once
#include <string>
#include <stdexcept>

class Player;

class InventoryItem {
private:
    std::string name;
    int value;
    int quantity;

public:
    InventoryItem(std::string name, int value, int quantity) : name(name), value(value), quantity(quantity) {}
    virtual ~InventoryItem() = default;

    virtual void useItem(Player& player, int index) {
        throw std::logic_error("useItem() must be overridden in derived classes.");
    }

    virtual void printItem()
    {
        throw std::logic_error("useItem() must be overridden in derived classes.");
    }

    std::string getName() const { return name; }
    int getValue() const { return value; }
    int getQuantity() const { return quantity; }
    void setQuantity(int quantity) { this->quantity = quantity; }
};