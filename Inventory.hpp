#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Inventory {
private:
	std::unordered_map<std::string, int> items{};
	std::unordered_map<std::string, int> stats{};
public:
	const int max_hp{};
	json save_data{};
	Inventory(const json& save);

	int get_stat(std::string stat);

	void set_stat(std::string stat, int amount);

	int get_item(std::string item);

	void set_item(std::string item, int amount);

	void save();

};

#endif
