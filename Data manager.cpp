#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <clocale>
#include "Data manager.hpp"
#include "Game manager.hpp"

using json = nlohmann::json;

void data_manager(std::ifstream& location, std::ifstream& enemy, std::ifstream& text, std::ifstream& save) {
    setlocale(LC_ALL, "RU");

    if (!location.is_open() or !enemy.is_open() or !text.is_open() or !save.is_open()) {
        std::cout << "Ошибка: один или больше необходимых файлов не найдены!\n";
    }

    json location_data, enemy_data, text_data, save_data;
    try {
        location >> location_data;
        enemy >> enemy_data;
        text >> text_data;
        save >> save_data;
    }
    catch (const json::parse_error& e) {
        std::cerr << "Ошибка парсинга JSON: " << e.what() << "\n";
        throw;
    }
}