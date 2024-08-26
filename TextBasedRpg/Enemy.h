#pragma once
#include <string>
#include <vector>
#include <iostream>

class Enemy {
private:
    std::string name;
    int health;
    int mana;
    int attack;
    int defense;
    std::vector<std::string> drops;
public:
    Enemy(std::string name, int health, int mana, int attack, int defense, std::vector<std::string> drops)
        : name(name), health(health), mana(mana), attack(attack), defense(defense), drops(drops) {}

    virtual void performAttack()
    {
        std::cout << "Enemy attacks!" << std::endl;
    }

    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getMana() const { return mana; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    std::vector<std::string> getDrops() const { return drops; }
};

class Goblin : public Enemy {
public:
    Goblin() : Enemy("Goblin", 10, 0, 2, 1, { "Gold" }) {
        std::cout << "A goblin has appeared!" << std::endl;
    }
    void performAttack() override {
        std::cout << "Goblin attacks with its club!" << std::endl;
    }
};

class Orc : public Enemy {
public:
    Orc() : Enemy("Orc", 20, 0, 4, 2, { "Gold", "Orc Tooth" }) {
        std::cout << "An orc has appeared!" << std::endl;
    }
    void performAttack() override {
        std::cout << "Orc swings its axe!" << std::endl;
    }
};

class Zombie : public Enemy {
public:
    Zombie() : Enemy("Zombie", 15, 0, 3, 1, { "Rotten Flesh" }) {
        std::cout << "A zombie has risen!" << std::endl;
    }
    void performAttack() override {
        std::cout << "Zombie tries to bite!" << std::endl;
    }
};

class Skeleton : public Enemy {
public:
    Skeleton() : Enemy("Skeleton", 12, 0, 3, 0, { "Bone", "Arrow" }) {
        std::cout << "A skeleton rattles into view!" << std::endl;
    }
    void performAttack() override {
        std::cout << "Skeleton fires an arrow!" << std::endl;
    }
};

class Wolf : public Enemy {
public:
    Wolf() : Enemy("Wolf", 8, 0, 3, 1, { "Wolf Pelt" }) {
        std::cout << "A wolf howls in the distance!" << std::endl;
    }
    void performAttack() override {
        std::cout << "Wolf lunges with its fangs!" << std::endl;
    }
};

class Bear : public Enemy {
public:
    Bear() : Enemy("Bear", 25, 0, 5, 3, { "Bear Claw", "Bear Pelt" }) {
        std::cout << "A bear roars fiercely!" << std::endl;
    }
    void performAttack() override {
        std::cout << "Bear swipes with its massive paw!" << std::endl;
    }
};