#include "Game manager.hpp"

using json = nlohmann::json;

int get_input();

void game_manager(std::map<std::string, Location>& locations, std::map<std::string, std::pair<bool, int>>& shop, std::map<std::string, Enemy>& enemies, Inventory& inv, std::map<std::string, Stick> sticks, Spell spell) {
	

	std::cout << "Choose what you want to do:\n"
			  << "1 : New game\n"
			  << "2 : Load your game\n"
			  << "3 : Exit\n"
			  << "Your input: ";
	while(true) {
		switch (get_input()) {
		case(1):
			std::cout << "\033[2J\033[1;1H"; //\033[2J Ч очистка экрана \033[1;1H Ч перемещение курсора в верхний левый угол
			inv.set_stat("max_hp", -inv.get_stat("max_hp") + 100);
			inv.set_stat("hp", -inv.get_stat("hp") + 100);
			inv.set_stat("max_mana", -inv.get_stat("max_mana") + 100);
			inv.set_stat("mana", -inv.get_stat("mana") + 100);
			inv.set_stat("lvl", -inv.get_stat("lvl") + 1);
			inv.set_stat("exp", -inv.get_stat("exp"));
			inv.set_stat("exp", -inv.get_stat("exp"));
			game(locations, shop, enemies, inv, sticks, spell);
			break;

		case(2):
			std::cout << "\033[2J\033[1;1H";
			game(locations, shop, enemies, inv, sticks, spell);
			break;

		case(3):
			std::cout << "Exiting the program. Have a great day!";
			exit(1);

		default:
			std::cout << "Choose from the list: ";
		}
	}
}

void game(std::map<std::string, Location>& locations, std::map<std::string, std::pair<bool, int>>& shop, std::map<std::string, Enemy>& enemies, Inventory& inv, std::map<std::string, Stick> sticks, Spell spell) {
	while (true) {
		std::cout << "What to do?\n"
				  << "1 : Go to shop\n"
				  << "2 : Go for an adventure\n"
				  << "3 : Exit game\n"
				  << "Your choice: ";
		switch (get_input()) {
		case(1):
			std::cout << "\nHello there, want to buy stuff?";
			for (auto& [item, pair] : shop) {
				if (pair.first and inv.get_item(item) >= 1) {
					std::cout << "\nDo you want to sell one " << item << "for " << pair.second << "?\n";
					if (get_input()) {
						std::cout << "Here is your money\n";
						inv.set_stat("gold", pair.second);
						inv.set_item(item, -1);
						inv.save();
					}
				}
			}
			std::cout << "\nBye bye\n";
			break;

		case(2):
			std::cout << "\033[2J\033[1;1H";
			show_locations(locations, shop, enemies, inv, sticks, spell);
			break;

		case(3):
			std::cout << "Exiting the program. Have a great day!";
			exit(1);

		default:
			std::cout << "Choose from the list: ";
		}
	}
}

void show_locations(std::map<std::string, Location>& locations, std::map<std::string, std::pair<bool, int>>& shop, std::map<std::string, Enemy>& enemies, Inventory& inv, std::map<std::string, Stick> sticks, Spell spell) {
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
			sticks.count("master_stick") == 1 ? temp = "master_stick" :
			sticks.count("intermedium_stick") == 1 ? temp = "intermedium_stick" : temp = "newbie_stick";
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

		case(2): {
			std::string temp{};
			sticks.count("master_stick") == 1 ? temp = "master_stick" :
				sticks.count("intermedium_stick") == 1 ? temp = "intermedium_stick" : temp = "newbie_stick";
			for (int i{}; i < locations.at("swamp").get_room(); i++) {
				if (fight_manager(enemies.at("swamp"), inv, sticks.at(temp), spell)) {
					std::cout << "You won\n";
				}
				else
					std::cout << "You lost";
			}
			choice = false;
			break;
		}

		case(3):
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