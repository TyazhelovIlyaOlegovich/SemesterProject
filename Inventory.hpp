#ifndef INVENTORY
#define INVENTORY

class Inventory {
private:
	int hp{};
	int xp{};
	int gold{};
	std::unordered_map<std::string, int> items{};
public:
	const int max_hp{};
	Inventory(int experience, int health, int max_health, int money, std::vector<std::string> item);

	int get_hp();

	void set_hp(int health);

	int get_xp();

	void set_xp(int experience);

	int get_gold();

	void set_gold(int money);

	int get_item(std::string item);

	void set_item(std::string item, int amount);

};

#endif
