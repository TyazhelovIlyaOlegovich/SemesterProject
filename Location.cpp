#include "Location.hpp"

static std::random_device rd;
static std::mt19937 gen(rd());

Location::Location(const std::string name, const std::string description, int min_room, int max_room) 
	: location_name(name),
	  location_desñription(description),
	  dist_of_rooms(min_room, max_room)
	{}

int Location::get_room() {
	return dist_of_rooms(gen);
}