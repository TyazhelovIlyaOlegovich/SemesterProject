#ifndef INVENTORY
#define INVENTORY

class Inventory {
private:
	/**int max_hp{};
	int hp{};
	int max_mana{};
	int mana{};
	int lvl{};
	int xp{};
	int gold{};*/
	std::unordered_map<std::string, int> items{};
	std::unordered_map<std::string, int> stats{};
public:
	const int max_hp{};
	Inventory(int experience, int health, int max_health, int mana, int max_mana, int level, int money, std::vector<std::pair<std::string, int>>& item);

	int get_stat(std::string& stat);

	void set_stat(std::string& stat, int amount);

	int get_item(std::string item);

	void set_item(std::string item, int amount);

};

#endif
