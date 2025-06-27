#include "Data manager.hpp"

using json = nlohmann::json;

void data_manager(const json& location_data, const json& enemy_data, json& text_data, const json& save_data, const json& elements_data, const json& sticks_data) {
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
            std::string drop = enemy["drop"];
            int max_hp = enemy["max_hp"];
            int hp = enemy["hp"];
            int exp = enemy["exp"];
            int min_dam = enemy["min_dam"];
            int max_dam = enemy["max_dam"];
            if (!text_data.contains(drop)) {
                text_data[drop] = "20";
            }
            enemies.emplace(enemy_key, Enemy(max_hp, hp, exp, min_dam, max_dam, drop, stat, name));
        }
    }

    std::ofstream output("text.json");
    output << text_data.dump(2);
    output.close();

    std::map<std::string, std::string> shop;
    for (auto& [shop_key, shop_data] : text_data.items()) {
        shop[shop_key] = shop_data;
    }

    std::map<std::string, Element> elements;
    for (auto& [element_key, element_data] : elements_data.items()) {
        std::string name = element_data["name"];
        int dmg = element_data["dmg"];
        int mana_cost = element_data["mana_cost"];
        elements.emplace(element_key, Element(name, dmg, mana_cost));
    }

    std::map<std::string, Stick> sticks;
    for (auto& [stick_key, stick_data] : sticks_data.items()) {
        std::string name = stick_data["name"];
        int cells = stick_data["cells"];
        int maxelements = stick_data["maxelements"];
        bool temp = stick_data["obtained"];
        if (temp) {
            sticks.emplace(stick_key, Stick(name, cells, maxelements, elements));
        }
    }

    Inventory inv(save_data);

    Spell spell("0", 0, 0, "0", elements);

    game_manager(locations, text_data, enemies, inv, sticks, spell);
}