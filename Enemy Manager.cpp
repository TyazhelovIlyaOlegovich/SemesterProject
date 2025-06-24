#include "Enemy Manager.hpp"

static std::random_device rd;
static std::mt19937 gen(rd());

Enemy::Enemy(int health, int experience, int minimum, int maximum, std::string status_effect, std::string enemy)
        : hp(health),
          exp(experience), //сколько экспы выпадет
          stat(status_effect), //вдруг что-то накладываем, наверное эффекты сделать в combat manager
          name(enemy),
          dist_of_damage(minimum, maximum) //разброс урона врага. ћожно просто два одинаковых числа вписать чтобы разброса не было
    {}

std::string Enemy::get_name() {
    return name;
}

int Enemy::get_hp() {
    return hp;
}

void Enemy::set_hp(int health) {
    hp += health;
}

int Enemy::get_damage() {
    return dist_of_damage(gen);
}

void Enemy::set_damange(int new_min, int new_max) {
    dist_of_damage.param(
        std::uniform_int_distribution<>::param_type(new_min, new_max)
    );
}