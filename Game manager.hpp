#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

using json = nlohmann::json;

void game_manager(const json& location_data, const json& enemy_data, const json& text_data, json& save_data);

#endif