

#ifndef FIGHT_MANAGER_HPP
#define FIGHT_MANAGER_HPP


#include <vector>
#include <iostream>
#include <fstream> 
#include <string>
#include <cstdio>
#include <random>
#include <sstream>
#include "Enemy Manager.hpp"
#include "Inventory.hpp"

#include "dllmain.hpp"
//#include "Game manager.hpp"


bool fight_manager(Enemy& enemy, //кого бьём
    Inventory& inv, //мы сами
    Stick stick, //наш посох
    Spell spell //заклинания
);
#endif