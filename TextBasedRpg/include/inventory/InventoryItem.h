#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include "ItemType.h"

class Player;

class InventoryItem {
private:
    ItemType m_type;
    std::string m_name;
    int m_value;
    int m_quantity;

public:
    InventoryItem(ItemType type, std::string name, int value, int quantity) : m_type(type), m_name(name), m_value(value), m_quantity(quantity) {}
    virtual ~InventoryItem() = default;

    virtual void useItem(Player&, int) {
        throw std::logic_error("useItem() must be overridden in derived classes.");
    }

    virtual void printItem()
    {
        std::cout << "  Name: " << m_name << '\n';
		std::cout << "  Value: " << m_value << '\n';
		std::cout << "  Quantity: " << m_quantity << '\n';
    }

    std::string getName() const { return m_name; }
    ItemType getType() const { return m_type; }
    int getValue() const { return m_value; }
    int getQuantity() const { return m_quantity; }
    void setQuantity(int quantity) { this->m_quantity = quantity; }
};