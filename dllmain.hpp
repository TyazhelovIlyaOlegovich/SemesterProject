
#ifndef DLLMAIN_HPP
#define DLLMAIN_HPP

#include <vector>
#include <iostream>
#include <fstream> 
#include <string>
#include <cstdio>
#include <random>
#include <sstream>
#include "Enemy Manager.hpp"
#include "Inventory.hpp"

using namespace std;

class Element {
private:
    std::string name;
    int dmg;
    int manacost;
public:

    Element(std::string name, int dmg, int manacost);

    int get_dmg();
    int get_manacost();
    std::string get_name();

};
class Spell {
private:
    std::string name;
    int mana;
    int DMGG;
    std::string DEBFF;
    std::map<std::string, Element> el;
public:

    Spell(const std::string name, int DMGG, int mana, const std::string DEBFF, std::map<std::string, Element>& elements);

    std::string get_name();
    int get_dmg();
    int get_manacost();
    std::string get_debuff();

    //void get_spell(string magic) {//сюда должно входить qwerrasdf
    //    for (int i=0; i < magic.length(); i++) {
    //        spell += std::string(1, magic[i]);
    //    }
    //}

    std::map<std::string, Element>& get_elements();

    std::vector <string> get_truesepll(std::string spell, int elements);//тута кароч надо найти противоречи€, сделать комбовые елементы (¬озвращает название заклини€ в 1 €чейке, во 2 урон,в 3 стоимость маны, в 4 остаточный эффект 0-ничего, fire гореть 3 хода по 2 дмг, toxic- 9ходов по 1 дмг, freeze- пропуск хода противника заорозка.)
    

};

class Stick {
private:
    //int mana;//ћана
    std::string name;
    int cells;//3-20 €чеек под магию
    int maxelements;//3-8 элементов в €чейке
    //vector <Element> magica[];//тута хранить магики-чуда закл€ти€
    std::map<std::string, Element> el;
public:
    Stick(std::string name, int cells, int maxelements, std::map<std::string, Element>& elements);

    std::string get_name();
    int get_cells();
    int get_maxelements();

    std::vector <Spell> spells;

    int get_amount();//кол-во зан€тых €чеек

    std::map<std::string, Element>& get_elements();

    void add_spell(int amount, std::vector<string> spell);//скок уже есть ?

    Spell get_spell(int amount);

    void delete_spell(int amount);
};








#endif