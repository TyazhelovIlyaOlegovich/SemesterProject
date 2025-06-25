#include "Data manager.hpp"
#include "Inventory.hpp"

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

    std::map<std::string, Location> locations;
    for (auto& [location_key, data] : location_data["locations"].items()) {
        std::string name = data["name"];
        std::string description = data["description"];
        int min_room = data["min_room"];
        int max_room = data["max_room"];
        locations.emplace(location_key, Location(name, description, min_room, max_room));
    }

    std::map<std::string, Enemy> enemies;
    for (auto& [enemy_key, data] : enemy_data["enemies"].items()) {
        for (auto& [temp, enemy] : data.items()) {
            std::string name = enemy["name"];
            std::string stat = enemy["stat"];
            int max_hp = enemy["max_hp"];
            int hp = enemy["hp"];
            int exp = enemy["exp"];
            int min_dam = enemy["min_dam"];
            int max_dam = enemy["max_dam"];
            enemies.emplace(enemy_key, Enemy(max_hp, hp, exp, min_dam, max_dam, stat, name));
        }
    }

    Inventory inv(save_data);


    game_manager(locations, text_data, enemies, inv);
}