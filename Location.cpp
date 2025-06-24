#include "Location.hpp"

Location::Location(const std::string name, const std::string description, int min_room, int max_room) 
	: location_name(name),
	  location_desription(description),
	  dist_of_rooms(min_room, max_room)
	{}

std::string Location::get_name() {
	return location_name;
}

std::string Location::get_description() {
	return location_desription;
}