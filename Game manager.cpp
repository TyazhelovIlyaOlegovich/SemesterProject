#include "Game manager.hpp"

using json = nlohmann::json;

int get_input();

void game_manager(std::map<std::string, Location>& locations, const json& text_data, std::map<std::string, Enemy>& enemies, Inventory& inv) {
	

	std::cout << "Choose what you want to do:\n"
			  << "1 : New game\n"
			  << "2 : Load your game\n"
			  << "3 : Exit\n"
			  << "Your input: ";
	while(true) {
		switch (get_input()) {
		case(1):
			std::cout << "\033[2J\033[1;1H"; //\033[2J Ч очистка экрана \033[1;1H Ч перемещение курсора в верхний левый угол
			inv.set_stat("max_hp", 100);
			inv.set_stat("hp", 100);
			inv.set_stat("max_mana", 100);
			inv.set_stat("mana", 100);
			inv.set_stat("lvl", 1);
			inv.set_stat("exp", 0);
			inv.set_stat("gold", 0);
			game(locations, text_data, enemies, inv);
			break;

		case(2):
			std::cout << "\033[2J\033[1;1H";
			game(locations, text_data, enemies, inv);
			break;

		case(3):
			std::cout << "Exiting the program. Have a great day!";
			exit(1);

		default:
			std::cout << "Choose from the list: ";
		}
	}
}

void game(std::map<std::string, Location>& locations, const json& text_data, std::map<std::string, Enemy>& enemies, Inventory& inv) {
	while (true) {
		std::cout << "Now we are in game";
		switch (get_input()) {
		case(1):
			//shop const json& text_data
		case(2):
			show_locations(locations, enemies, inv);
			break;

		case(3):
			std::cout << "Exiting the program. Have a great day!";
			exit(1);

		default:
			std::cout << "Choose from the list: ";
		}
	}
}

void show_locations(std::map<std::string, Location>& locations, std::map<std::string, Enemy>& enemies, Inventory& inv) {
	int count{ 0 };
	for (const auto& [location_key, data] : locations) {
		std::cout << count << " : " << location_key << '\n';
		std::cout << data.location_desсription << '\n';
		count++;
	}

	std::cout << "Your input: ";
	while (true) {
		switch (get_input()) {
		case(1):
			std::cout << locations.at("forest").get_room();
			break;
		}
	}
}

int get_input() {
	std::string input{};
	std::getline(std::cin, input);

	return std::stoi(input);
}