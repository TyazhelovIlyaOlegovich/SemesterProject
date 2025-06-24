#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include "Game manager.hpp"

using json = nlohmann::json;

int get_input();

void game_manager(const json& location_data, const json& text_data, const json& enemy_data, json& save_data) {
	std::cout << "Choose what you want to do:\n"
			  << "1:New game\n"
			  << "2:Load your game\n"
			  << "3:Exit\n"
			  << "Your input: ";
	while(true) {
		switch (get_input()) {
		case(1):
			std::cout << "\033[2J\033[1;1H"; //\033[2J Ч очистка экрана
			save_data["max_hp"] = 100;
			save_data["hp"] = 100;
			save_data["max_mana"] = 100;
			save_data["mana"] = 100;
			save_data["lvl"] = 1;
			save_data["exp"] = 0;
			save_data["gold"] = 0;
			game(location_data, text_data, enemy_data, save_data);

		case(2):
			std::cout << "\033[2J";
			game(location_data, text_data, enemy_data, save_data);

		case(3):
			std::cout << "Exiting the program. Have a great day!";
			get_input();
			exit(1);

		default:
			std::cout << "Choose from the list: ";
		}
	}
}

void game(const json& location_data, const json& text_data, const json& enemy_data, json& save_data) {
	while (true) {

		switch (get_input()) {
		case(1):

		case(2):
			
		case(3):
			std::cout << "Exiting the program. Have a great day!";
			get_input();
			exit(1);

		default:
			std::cout << "\033[2J";
			std::cout << "Choose from the list: ";
		}
	}
}

int get_input() {
	std::string input{};
	std::getline(std::cin, input);

	return std::stoi(input);
}