#include <unordered_map>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "Inventory.hpp"

using json = nlohmann::json;

Inventory::Inventory(int max_health, int health, int max_mana, int mana, int level, int experience, int money, std::vector<std::pair<std::string, int>>& item, json& save) 
	: save_data(save)
		{
		for (const auto& temp : item) {
			items[temp.first] = temp.second; 
		}
		stats["max_hp"] = max_health;
		stats["hp"] = health;
		stats["max_mana"] = max_mana;
		stats["mana"] = mana;
		stats["lvl"] = level;
		stats["exp"] = experience;
		stats["gold"] = money;
	}

int Inventory::get_stat(std::string stat) {
	return stats[stat];
}

void Inventory::set_stat(std::string& stat, int amount) {
	if (stat == "exp" and stats[stat] + amount >= 100) {
		stats["lvl"] += 1;
		stats["exp"] = stats["exp"] + amount - 100;
		stats["max_hp"] += 10;
		stats["hp"] = stats["max_hp"];
		stats["max_mana"] += 10;
		stats["mana"] = stats["max_mana"];
	}
	else {
		stat == "hp" and stats["hp"] + amount > stats["max_hp"] ? stats["hp"] = stats["max_hp"] : stats["hp"] += amount;
		stat == "hp" and stats["hp"] <= 0 ? stats["hp"] + amount == 0 : stats["hp"] += amount;
		stat == "mana" and stats["mana"] + amount > stats["max_mana"] ? stats["mana"] = stats["max_mana"] : stats["mana"] += amount;
	}
}

int Inventory::get_item(std::string item) {
	return items[item];
}

void Inventory::set_item(std::string item, int amount) {
	items[item] += amount;
}

void Inventory::save() {
	save_data["max_hp"] = get_stat("max_hp");
	save_data["hp"] = get_stat("hp");
	save_data["max_mana"] = get_stat("max_mana");
	save_data["mana"] = get_stat("mana");
	save_data["lvl"] = get_stat("lvl");
	save_data["exp"] = get_stat("exp");
	save_data["gold"] = get_stat("gold");
	for (const auto& pair : items) {
		save_data[pair.first] = pair.second;
	}
}