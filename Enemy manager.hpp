#ifndef ENEMY_MANAGER_HPP
#define ENEMY_MANAGER_HPP

class Enemy {
 private:
    int hp{};
    std::uniform_int_distribution<> dist_of_damage;
    std::string stat{};
 public:
    const int exp{};
    //const int speed{};
    const std::string name{};

    Enemy(int health, int experience, int minimum, int maximum, std::string status_effect, std::string enemy);

    int get_hp();

    void set_hp(int health);

    int get_damage();

    void set_damange(int new_min, int new_max);
};

#endif