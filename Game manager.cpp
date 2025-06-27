#include "Game manager.hpp"

using json = nlohmann::json;

int get_input();

void game_manager(std::map<std::string, Location>& locations, const json& text_data, std::map<std::string, Enemy>& enemies, Inventory& inv, std::map<std::string, Stick> sticks, Spell spell) {
	

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
			game(locations, text_data, enemies, inv, sticks, spell);
			break;

		case(2):
			std::cout << "\033[2J\033[1;1H";
			game(locations, text_data, enemies, inv, sticks, spell);
			break;

		case(3):
			std::cout << "Exiting the program. Have a great day!";
			exit(1);

		default:
			std::cout << "Choose from the list: ";
		}
	}
}

void game(std::map<std::string, Location>& locations, const json& text_data, std::map<std::string, Enemy>& enemies, Inventory& inv, std::map<std::string, Stick> sticks, Spell spell) {
	while (true) {
		std::cout << "What to do?\n"
				  << "1 : Go to shop\n"
				  << "2 : Go for an adventure\n"
				  << "3 : Exit game\n"
				  << "Your choice: ";
		switch (get_input()) {
		case(1):
			//shop const json& text_data
		case(2):
			std::cout << "\033[2J\033[1;1H";
			show_locations(locations, enemies, inv, sticks, spell);
			break;

		case(3):
			std::cout << "Exiting the program. Have a great day!";
			exit(1);

		default:
			std::cout << "Choose from the list: ";
		}
	}
}

void show_locations(std::map<std::string, Location>& locations, std::map<std::string, Enemy>& enemies, Inventory& inv, std::map<std::string, Stick> sticks, Spell spell) {
	int count{ 1 };
	for (const auto& [location_key, data] : locations) {
		std::cout << count << " : " << data.location_name << ' ';
		std::cout << data.location_desсription << '\n';
		count++;
	}

	bool choice{ true };
	while (choice) {
		std::cout << "Your input: ";
		switch (get_input()) {
		case(1): {
			std::string temp{};
			sticks.count("master_stick") ? temp = "master_stick" :
			sticks.count("intermedium_stick") ? temp = "intermedium_stick" :
			sticks.count("newbie_stick") ? temp = "newbie_stick" : 0;
			for (int i{}; i < locations.at("forest").get_room(); i++) {
				if (fight_manager(enemies.at("forest"), inv, sticks.at(temp), spell)) {
					std::cout << "You won\n";
				}
				else
					std::cout << "You lost";
			}
			choice = false;
			break;
		}

		case(2):
			std::cout << locations.at("swamp").get_room();
			choice = false;
			break;

		case(3):
			std::cout << locations.at("forest").get_room();
			break;

		case(4):
			choice = false;
			break;

		default:
			std::cout << "Choose from the list: ";
		}
	}
}

int get_input() {
	std::string input{};
	std::getline(std::cin, input);

	return std::stoi(input);
}