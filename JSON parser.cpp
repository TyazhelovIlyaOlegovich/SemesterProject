#include <fstream>
#include "Data manager.hpp"

int main() {
    std::ifstream location("location.json");
    std::ifstream enemy("enemy.json");
    std::ifstream text("text.json");
    std::ifstream save("save.json");
    
    data_manager(location, enemy, text, save);

    return 0;
}