#pragma once

enum class EnemyType {
    // Forest Enemies
    ForestStart = 100,
    Goblin,
    Wolf,
    Bear,
    ForestEnd = 104,

    // Cave Enemies
    CaveStart = 200,
    Orc,
    Zombie,
    Skeleton,
    CaveEnd = 204,

    // Desert Enemies
    DesertStart = 300,
    DesertBandit,
    Scorpion,
    SandWorm,
    DesertEnd = 304,

    // Mountain Enemies
    MountainStart = 400,
    IceHawk,
    Slime,
    RockGolem,
    MountainEnd = 404
};