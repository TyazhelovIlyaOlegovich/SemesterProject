#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <nlohmann/json.hpp>
#include "Location.hpp"
#include "Inventory.hpp"
#include "Enemy Manager.hpp"

using json = nlohmann::json;

void game_manager(std::map<std::string, Location>& locations, const json& text_data, std::map<std::string, Enemy>& enemies, Inventory& inv);

void game(std::map<std::string, Location>& locations, const json& text_data, std::map<std::string, Enemy>& enemies, Inventory& inv);

void show_locations(std::map<std::string, Location>& locations, std::map<std::string, Enemy>& enemies, Inventory& inv);

int get_input();

#endif