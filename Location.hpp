#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <iostream>
#include <string>
#include <random>

class Location {
public:
	const std::uniform_int_distribution<> dist_of_rooms;
	const std::string location_name{};
	const std::string location_desription{};

	Location(const std::string name, const std::string description, int min_room, int max_room);

	std::string get_name();

	std::string get_description();

};

#endif 
