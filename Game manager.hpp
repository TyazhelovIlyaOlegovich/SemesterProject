#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <nlohmann/json.hpp>
#include "Location.hpp"
#include "Inventory.hpp"
#include "Enemy Manager.hpp"
//#include "dllmain.cpp"
//#include "Fight_manager.cpp"

using json = nlohmann::json;

void game_manager(std::map<std::string, Location>& locations, const json& text_data, std::map<std::string, Enemy>& enemies, Inventory& inv, std::map<std::string, Stick> sticks, Spell spell);

void game(std::map<std::string, Location>& locations, const json& text_data, std::map<std::string, Enemy>& enemies, Inventory& inv, std::map<std::string, Stick> sticks, Spell spell);

void show_locations(std::map<std::string, Location>& locations, std::map<std::string, Enemy>& enemies, Inventory& inv, std::map<std::string, Stick> sticks, Spell spell);

int get_input();

#endif