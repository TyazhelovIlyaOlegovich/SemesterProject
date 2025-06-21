#include <unordered_map>
#include <string>
#include <vector>
#include "Inventory.hpp"

Inventory::Inventory(int experience, int health, int max_health, int money, std::vector<std::string> item)
		: max_hp(max_health),
		  hp(health), 
		  xp(experience), 
		  gold(money)
	{
		for (std::string temp : item) { items[temp] = 0; }
	}

int Inventory::get_hp() {
	return hp;
}

void Inventory::set_hp(int health) {
	hp = health;
}

int Inventory::get_xp() {
	return xp;
}

void Inventory::set_xp(int experience) {
	xp += experience;
}

int Inventory::get_gold() {
	return gold;
}

void Inventory::set_gold(int money) {
	gold += money;
}

int Inventory::get_item(std::string item) {
	return items[item];
}

void Inventory::set_item(std::string item, int amount) {
	items[item] += amount;
}