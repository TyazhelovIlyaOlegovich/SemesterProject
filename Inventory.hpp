#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <unordered_map>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Inventory {
private:
	std::unordered_map<std::string, int> items{};
	std::unordered_map<std::string, int> stats{};
public:
	const int max_hp{};
	json save_data{};
	Inventory(int experience, int health, int max_health, int mana, int max_mana, int level, int money, std::vector<std::pair<std::string, int>>& item, json& save_data);

	int get_stat(std::string stat);

	void set_stat(std::string stat, int amount);

	int get_item(std::string item);

	void set_item(std::string item, int amount);

	void save();

};

#endif
