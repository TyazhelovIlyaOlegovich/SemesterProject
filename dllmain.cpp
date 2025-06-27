﻿// dllMAGIC!!!!!!!!!!! АЛАХАУИДАВРА!


#include "dllmain.hpp"





    Element::Element(std::string name, int dmg, int manacost)
        :name(name), dmg(dmg), manacost(manacost) {
    };

    int Element::get_dmg() {
        return this->dmg;
    };
    int Element::get_manacost() {
        return this->manacost;
    };
    std::string Element::get_name() {
        return this->name;
    };



    Spell::Spell(const std::string name, int DMGG, int mana, const std::string DEBFF, std::map<std::string, Element>& elements)
        : name(name),//имя
        mana(mana), //скок маны жрёт
        DMGG(DMGG), //скок дамажет противника
        DEBFF(DEBFF),//дебафф
        el(elements)
    {
    }

    std::string Spell::get_name() { return this->name; }
    int Spell::get_dmg() { return this->DMGG; }
    int Spell::get_manacost() { return this->mana; }
    std::string Spell::get_debuff() { return this->DEBFF; }

    //void get_spell(string magic) {//сюда должно входить qwerrasdf
    //    for (int i=0; i < magic.length(); i++) {
    //        spell += std::string(1, magic[i]);
    //    }
    //}

    std::map<std::string, Element>& Spell::get_elements() {
        return el;
    }

    std::vector <string> Spell::get_truesepll(std::string spell, int elements)//тута кароч надо найти противоречия, сделать комбовые елементы (Возвращает название заклиния в 1 ячейке, во 2 урон,в 3 стоимость маны, в 4 остаточный эффект 0-ничего, fire гореть 3 хода по 2 дмг, toxic- 9ходов по 1 дмг, freeze- пропуск хода противника заорозка.)
    {
        std::vector <string> truespell;//название заклинания/урон/дебаф


        //1 буквы элементов как обозначения, ибо сейчас начнёться их подсчёт
        int f = 0;//fire
        int w = 0;//water
        int l = 0;//light
        int sh = 0;//sheild
        int d = 0;//death
        int c = 0;//cold
        int st = 0;//stone
        int h = 0;//heal
        //ниже комбо эл-ты(занимают 1 яч элемента вместо 2х)
        int to = 0;//toxic
        int ic = 0;//ice
        int ste = 0;//steam

        int maxelements = elements;//для нижней формулы ибло придёться проводить манипуляции с этой переменной
        //подсчёт заклинания снизу
        for (int i = 0; i < spell.size() and i < maxelements; i++)
        {

            //чуть не закончено, надо побольше сделать переборов разных ситуаций
            //сам подсчёт
            //если встречаються взаимно не соеденяющиеся то уничтожают последний, если соединяються, то добавляем соеденённый эл-т и убираем другие 2.
            if (to_string(spell[i]) == "f") {
                f += 1;
                if (f > 0 and w > 0) { ste += 1; f -= 1; w -= 1; maxelements += 1; }//пар вода + огонь
                if (f > 0 and c > 0) { f -= 1; c -= 1; maxelements += 2; }//незя холод + огонь
                if (f > 0 and ic > 0) { ic -= 1; f -= 1; w += 1; maxelements += 1; }//лёд(холод+вода)+огон
            }
            else if (to_string(spell[i]) == "w") {
                w += 1;
                if (d > 0 and w > 0) { to++; w -= 1; d -= 1; maxelements += 1; }//токсин смерть + вода
                if (f > 0 and w > 0) { ste += 1; f -= 1; w -= 1; maxelements += 1; }//пар вода + огонь
                if (st > 0 and w > 0) { l -= 1; w -= 1; maxelements += 2; }//незя молнию и воду

            }
            else if (to_string(spell[i]) == "a") {
                l += 1;
                if (st > 0 and l > 0) { l -= 1; st -= 1; maxelements += 2; }//незя камень и молнию(хз почему првила магики)
                if (st > 0 and w > 0) { l -= 1; w -= 1; maxelements += 2; }//незя молнию и воду
            }
            else if (to_string(spell[i]) == "e") { sh += 1; }//это типо щит, просто пока пусть будет ток цена...

            else if (to_string(spell[i]) == "s") {
                d += 1;
                if (d > 0 and w > 0) { to++; w -= 1; d -= 1; maxelements += 1; }//токсин смерть + вода
                if (h > 0 and d > 0) { h -= 1; d -= 1; maxelements += 2; }//незя хилить + смерт
            }
            else if (to_string(spell[i]) == "r") {
                c += 1;
                if (f > 0 and c > 0) { f -= 1; c -= 1; maxelements += 2; }//незя холод + огонь
                if (ste > 0 and c > 0) { ste -= 1; c -= 1; w += 1; maxelements += 1; }//пар + холод = вода
                if (c > 0 and w > 0) { ic += 1; c -= 1; w -= 1; maxelements += 1; }// лёд вода+мороз
            }
            else if (to_string(spell[i]) == "d") {
                st += 1;
                if (st > 0 and l > 0) { l -= 1; st -= 1; maxelements += 2; }//незя камень и молнию(хз почему првила магики)
            }
            else if (to_string(spell[i]) == "q") {
                h += 1;
                if (h > 0 and d > 0) { h -= 1; d -= 1; maxelements += 2; }//незя хилить + смерт
            }


            // if (f > 0 and w > 0) { st += 1; f -= 1; w -= 1; maxelements += 1; }//пар вода + огонь
             //if (d > 0 and w > 0) { to++; w -= 1; d -= 1; maxelements += 1; }//токсин смерть + вода
             //if (c > 0 and w > 0) { ic += 1; c -= 1; w -= 1; maxelements += 1; }// лёд вода+мороз
            //if (l>0 and d>1){ }
        }

        bool sheld = 0;//для понимания это всё таки будет просто защитное или всё таки атакующее

        if (sh > 0 and (w + l + d + c + st + h + to + ic + ste) > 0) { std::cout << "This spell is sheid? 0-nope(remove sheild) 1-yes(it will remove other elements)\n"; std::cin >> sheld; std::cout << "\n"; }

        //щит...
        if (sheld) { truespell.push_back("Sheild"); truespell.push_back("0"); truespell.push_back(std::to_string(get_elements().at("shield").get_manacost())), truespell.push_back("0"); }

        //а тут... это надо типо название + урон + дебаф
        else {
            std::string spellname = "";
            int manacost = 0;
            std::string debuff = "0";
            int dmg = 0;

            if (f > 0) { spellname += "Fire "; manacost += get_elements().at("fire").get_manacost(); dmg += get_elements().at("fire").get_dmg(); }
            if (w > 0) { spellname += "Water "; manacost += get_elements().at("water").get_manacost(); dmg += get_elements().at("water").get_dmg(); }
            if (l > 0) { spellname += "Light "; manacost += get_elements().at("light").get_manacost(); dmg += get_elements().at("light").get_dmg(); }
            if (d > 0) { spellname += "Death "; manacost += get_elements().at("death").get_manacost(); dmg += get_elements().at("death").get_dmg(); }
            if (st > 0) { spellname += "Stone "; manacost += get_elements().at("stone").get_manacost(); dmg += get_elements().at("stone").get_dmg(); }
            if (h > 0) { spellname += "Heal "; manacost += get_elements().at("heal").get_manacost(); dmg += get_elements().at("heal").get_dmg(); }
            if (c > 0) { spellname += "Cold "; manacost += get_elements().at("cold").get_manacost(); dmg += get_elements().at("cold").get_dmg(); }
            if (to > 0) { spellname += "Toxic "; manacost += get_elements().at("toxic").get_manacost(); dmg += get_elements().at("toxic").get_dmg(); }
            if (ic > 0) { spellname += "Ice "; manacost += get_elements().at("ice").get_manacost(); dmg += get_elements().at("ice").get_dmg(); }
            if (ste > 0) { spellname += "Steam "; manacost += get_elements().at("steam").get_manacost(); dmg += get_elements().at("steam").get_dmg(); }

            //приоритет в дебафе будет идти на заморозку, потом на токсик и только потом на огонь ;p
            if (c > 0) { debuff = "freeze"; }
            else if (to > 0) { debuff = "toxic"; }
            else if (f > 0) { debuff = "fire"; }
            truespell.push_back(spellname); truespell.push_back(std::to_string(dmg)); truespell.push_back(std::to_string(manacost)), truespell.push_back(debuff);
        }



        return truespell;
    }



    Stick::Stick(std::string name, int cells, int maxelements, std::map<std::string, Element>& elements)
        : name(name),
        cells(cells),//3-20 ячеек под магию
        maxelements(maxelements),//3-8 элементов в ячейке
        el(elements)
    {
    }

    std::string Stick::get_name() { return this->name; }
    int Stick::get_cells() { return this->cells; }
    int Stick::get_maxelements() { return this->maxelements; }

   

    int Stick::get_amount() { return spells.size(); }//кол-во занятых ячеек

    std::map<std::string, Element>& Stick::get_elements() {
        return el;
    }

    void Stick::add_spell(int amount, std::vector<string> spell)//скок уже есть ?
    {
        Spell sp(spell[0], std::stoi(spell[1]), std::stoi(spell[2]), spell[3], get_elements());
        if (amount < cells) { spells.push_back(sp); }
        else { std::cout << "У тя заняты ячейки"; }
    }

    Spell Stick::get_spell(int amount) {
        if (amount < spells.size()) { return spells[amount]; }
        else {
            std::cout << "NOTHING IS HERE\n";  Spell nothing("0", 0, 0, "0", get_elements()); return nothing;
        }
    }

    void Stick::delete_spell(int amount) {//удолить спелл на этом номере
        spells.erase(spells.begin() + amount);
    }

