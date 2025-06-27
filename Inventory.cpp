#include "Inventory.hpp"

using json = nlohmann::json;

Inventory::Inventory(const json& save) 
	: save_data(save)
		{
		for (const auto& [key, value] : save["items"].items()) {
			items[key] = value;
		}
		stats.emplace("max_hp", save["max_hp"]);
		stats.emplace("hp", save["hp"]);
		stats.emplace("max_mana", save["max_mana"]);
		stats.emplace("mana", save["mana"]);
		stats.emplace("lvl", save["lvl"]);
		stats.emplace("exp", save["exp"]);
		stats.emplace("gold", save["gold"]);
		stats.emplace("hp_heal", save["hp_heal"]);
		stats.emplace("mana_heal", save["mana_heal"]);
	}

int Inventory::get_stat(std::string stat) {
	std::cout << "\nInventory " << stat << ' ' << stats[stat];
	return stats.at(stat);
}

void Inventory::set_stat(std::string stat, int amount) {
	if (stat == "exp" and stats[stat] + amount >= 100) {
		stats["lvl"] += 1;
		stats["exp"] = stats["exp"] + amount - 100;
		stats["max_hp"] += 10;
		stats["hp"] = stats["max_hp"];
		stats["max_mana"] += 10;
		stats["mana"] = stats["max_mana"];
	}
	else if (stat == "hp_heal") {
		stats["hp"] += 20;
		stats["mana_heal"]--;
	}
	else if (stat == "mana_heal") {
		stats["mana"] += 20;
		stats["mana_heal"]--;
	}
	else if(stat == "hp" or stat == "mana") {
		stat == "hp" and stats["hp"] + amount > stats["max_hp"] ? stats["hp"] = stats["max_hp"] : stats["hp"] += amount;
		stat == "hp" and stats["hp"] + amount <= 0 ? stats["hp"] = 0: stats["hp"] += amount;
		stat == "mana" and stats["mana"] + amount > stats["max_mana"] ? stats["mana"] = stats["max_mana"] : stats["mana"] += amount;
		stat == "mana" and stats["mana"] + amount <= 0 ? stats["mana"] = 0 : stats["mana"] += amount;
	}
	else if (stat == "exp") {
		stats[stat] += amount;
	}
	else if (stat == "gold") {
		stats[stat] += amount;
	}
}

int Inventory::get_item(std::string item) {
	return items[item];
}

void Inventory::set_item(std::string item, int amount) {
	items[item] += amount;
}

void Inventory::save() {
	std::ofstream output("save.json");
	save_data["max_hp"] = get_stat("max_hp");
	save_data["hp"] = get_stat("hp");
	save_data["max_mana"] = get_stat("max_mana");
	save_data["mana"] = get_stat("mana");
	save_data["lvl"] = get_stat("lvl");
	save_data["exp"] = get_stat("exp");
	save_data["gold"] = get_stat("gold");
	for (const auto& pair : items) {
		save_data["items"][pair.first] = pair.second;
	}
	output << save_data.dump(2);
	output.close();
}