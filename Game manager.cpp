#include <iostream>
#include <nlohmann/json.hpp>
#include "Game manager.hpp"

using json = nlohmann::json;

void game_manager(const json& location_data, const json& enemy_data, const json& text_data, json& save_data) {
	//location_data частично в dialog system
	//enemy_data частично в dialog system
	//text_data полностью? в dialog system
	bool in_fight{ false };

	if (in_fight) {
		//combat_system(save_data["player"]["hp"])>;

	}

}