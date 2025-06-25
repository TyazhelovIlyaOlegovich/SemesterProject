#ifndef ENEMY_MANAGER_HPP
#define ENEMY_MANAGER_HPP

#include <string>
#include <random>

class Enemy {
 private:
    int hp{};
    std::uniform_int_distribution<> dist_of_damage;
    std::string stat{};
 public:
    const int exp{};
    const int max_hp{};
    const std::string drop{};
    const std::string name{};

    Enemy(int max_health, int health, int experience, int minimum, int maximum, std::string loot, std::string status_effect, std::string enemy);

    int get_hp();

    void set_hp(int health);

    void refresh_hp();

    std::string get_status();

    void set_status(std::string status);

    int get_damage();

    void set_damange(int new_min, int new_max);
};

#endif