#pragma once
#include <string>
#include <stdexcept>

class Player;

class InventoryItem {
private:
    std::string m_name;
    int m_value;
    int m_quantity;

public:
    InventoryItem(std::string name, int value, int quantity) : m_name(name), m_value(value), m_quantity(quantity) {}
    virtual ~InventoryItem() = default;

    virtual void useItem(Player&, int) {
        throw std::logic_error("useItem() must be overridden in derived classes.");
    }

    virtual void printItem()
    {
        throw std::logic_error("useItem() must be overridden in derived classes.");
    }

    std::string getName() const { return m_name; }
    int getValue() const { return m_value; }
    int getQuantity() const { return m_quantity; }
    void setQuantity(int quantity) { this->m_quantity = quantity; }
};