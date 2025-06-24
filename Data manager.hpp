#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP

#include <iostream>
#include <fstream>
#include <clocale>
#include <nlohmann/json.hpp>
#include "Game manager.hpp"

void data_manager(std::ifstream& location, std::ifstream& enemy, std::ifstream& text, std::ifstream& save);

#endif