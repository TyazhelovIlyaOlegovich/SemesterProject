#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP

#include <clocale>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Inventory.hpp"
#include "Game manager.hpp"
//#include "dllmain.cpp"

void data_manager(const json& location_data, const json& enemy_data, json& text_data, const json& save_data, const json& elements_data, const json& sticks_data);

#endif