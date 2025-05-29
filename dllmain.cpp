// dllMAGIC!!!!!!!!!!! АЛАХАУИДАВРА!
#include <vector>
#include <iostream>
#include <fstream> 
#include <string>
#include <cstdio>
#include <random>
#include <sstream>
using namespace std;
class Element {
private:
    std::string name;
    int dmg;
    int manacost;
public:
    
    Element(std::string name, int dmg, int manacost)
        :name(name), dmg(dmg), manacost(manacost) {
    };

    int GetDMG() {
        return this->dmg;
    };
    int GetManacost() {
        return this->manacost;
    };
    std::string GetName() {
        return this->name;
    };
};
class Spell : public Element {
private:
    
public:
    Element water = Element("water", 0, 5);//непонятная штука
    Element fire = Element("fire", 14, 6);
    Element light = Element("light", 17, 7);
    Element heal = Element("heal", -10, 5);
    Element sheild = Element("sheild", 0, 10);//непонятная штука
    Element death = Element("death", 20, 9);
    Element cold = Element("cold", 8, 6);
    Element stone = Element("stone", 15, 5);
    //елементы из комбо снизу
    Element toxic = Element("toxic", 25, 14);//смерт+вода
    Element ice = Element("ice", 18, 11); //вода+холод
    Element steam = Element("steam", 19, 11);//вода+огонь

    std::vector <string>  spell;

    void GetSpell(string magic) {//сюда должно входить qwerrasdf
        for (int i; i < magic.length(); i++) {
            spell.push_back(std::string (1,magic[i]));
        }
    }
    std::vector <string> GetTrueSpell(){//тута кароч надо найти противоречия, сделать комбовые елементы

    }

};
class Stick : public Spell {
private:
    int mana;//Мана
    int cells;//3-20 ячеек под магию
    int elements;//3-8 элементов в ячейке
    vector <Spell> magica[];//тута хранить магики-чуда заклятия
public:




};