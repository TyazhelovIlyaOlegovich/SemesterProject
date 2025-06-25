#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <iostream>
#include <string>
#include <random>

class Location {
private:
	std::uniform_int_distribution<> dist_of_rooms;
public:
	const std::string location_name{};
	const std::string location_desñription{};

	Location(const std::string name, const std::string description, int min_room, int max_room);

	int get_room();

};

#endif 
