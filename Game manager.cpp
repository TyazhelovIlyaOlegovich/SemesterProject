#include <iostream>
#include <nlohmann/json.hpp>
#include "Game manager.hpp"

using json = nlohmann::json;

void game_manager(const json& location_data, const json& enemy_data, const json& text_data, json& save_data) {
	//location_data частично в dialog system
	//enemy частично написана, но требует поправок для загрузки от combat manager
	//text_data полностью? в dialog system

	//combat_system(save_data["player"]["hp"], save_data["player"]["заклинания"], enemy полностью?);
	//чтобы подключтьб в combat manager enemy manager, надо среди подключаемых библиотек написать #include "Enemy Manager.hpp"
}