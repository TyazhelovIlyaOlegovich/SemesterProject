#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Data manager.hpp"

using json = nlohmann::json;

int main() {
    setlocale(LC_ALL, "RU");

    std::ifstream location("location.json");
    std::ifstream enemy("enemy.json");
    std::ifstream text("text.json");
    std::ifstream save("save.json");
    std::ifstream elements("elements.json");

    if (!location.is_open() or !enemy.is_open() or !text.is_open() or !save.is_open()) {
        std::cout << "Ошибка: один или больше необходимых файлов не найдены!\n";
    }

    json location_data, enemy_data, text_data, save_data, elements_data;
    try {
        location >> location_data;
        enemy >> enemy_data;
        text >> text_data;
        save >> save_data;
        elements >> elements_data;
    }
    catch (const json::parse_error& e) {
        std::cerr << "Ошибка парсинга JSON: " << e.what() << "\n";
        throw;
    }
    
    location.close();
    enemy.close();
    text.close();
    save.close();
    elements.close();
    
    data_manager(location_data, enemy_data, text_data, save_data, elements_data);

    return 0;
}