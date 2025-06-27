#pragma once

#include "Fight_manager.hpp"

bool fight_manager(Enemy& enemy, //кого бьём
    Inventory& inv, //мы сами
    Stick stick, //наш посох
    Spell spell //заклинания
)
{
    int enhp = enemy.get_hp();//хп врага

    bool winorlose = 0;//для спец случев
    bool sheild = 0;
    std::string oldstatus = "";
    int checkstatus = 0;
    int freezemob = 0;//если равен 1 то не наносит урон в раунде
    std::cout << "GET READY TO FIGHT WITH " << enemy.name << "\n 3... 2... 1... \n   FIGHT \n";

    while (true) {
        int answer = 0;



        while (answer <= stick.get_amount()) {
            std::cout << enemy.name << " " << enemy.get_hp() << "\n" << "\n";

            std::cout << "Your Health " << inv.get_stat("hp") << ".  Your Mana " << inv.get_stat("mana") << ".\n";

            std::cout << "Your cells:\n";

            if (stick.get_amount() != 0) {
                for (int i = 0; i < stick.get_cells(); i++) {
                    std::cout << std::to_string(i + 1) << " " << stick.get_spell(i).get_name() << " mana's cost " << std::to_string(stick.get_spell(i).get_manacost());
                }
            }
            else { std::cout << "Nothing"; }

            if (answer == 0) {
                std::cout << "If you want use cell click number of it (if you did it you can't create new one), if you want create new one click 0\n";
                std::cout << "For end press any Number what's not 0 or cell\n";

                std::cin >> answer;

                if (answer == 0) {
                    std::string set_spell = "";
                    std::cout << "\nq-heal w-water e-sheild r-cold a-light(electric) s-death d-stone f-fire\n";
                    std::cin >> set_spell;
                    std::cout << "\n";
                    stick.add_spell(stick.get_amount(), spell.get_truesepll(set_spell, stick.get_maxelements()));
                }
            }
            else if (answer > 0 and answer < stick.get_amount()) {

                std::cout << "\nIf you want use cell click number of it or any ohter numbers for skip move\n";
                std::cin >> answer;

                if (stick.get_spell(answer).get_manacost() <= inv.get_stat("mana")) {
                    if (stick.get_spell(answer).get_name() != "sheild" and stick.get_spell(answer).get_name() != "Nothing") {
                        inv.set_stat("mana", -1 * stick.get_spell(answer).get_manacost());
                        enemy.set_hp((-1 * stick.get_spell(answer).get_dmg()));
                        enemy.set_status(stick.get_spell(answer).get_debuff());

                    }
                    else if (stick.get_spell(answer).get_name() == "sheild") { sheild = 1; }
                }

            }

        }

        if (enemy.get_status() != oldstatus and enemy.get_status() != "0") {
            if (enemy.get_status() == "fire") {
                if (checkstatus == 0) { checkstatus = 2; enemy.set_hp(-1 * 2); }
                else { checkstatus -= 1; enemy.set_hp(-1 * 2); }
            }
            if (enemy.get_status() == "toxic") {
                if (checkstatus == 0) { checkstatus = 8; enemy.set_hp(-1 * 1); }
                else { checkstatus -= 1; enemy.set_hp(-1 * 2); }
            }
            if (enemy.get_status() == "freeze") {
                if (checkstatus == 0) { checkstatus = 0; freezemob = 1; }
                else { checkstatus -= 1; enemy.set_hp(-1 * 2); }
            }

            else if (checkstatus - 1 == 0) { enemy.set_status("0"); }
        }
        else if (enemy.get_status() == oldstatus and oldstatus != "0") {
            if (enemy.get_status() == "fire") {
                if (checkstatus == 0) { checkstatus = 2; enemy.set_hp(-1 * 2); }
                else { checkstatus -= 1; enemy.set_hp(-1 * 2); }
            }
            if (enemy.get_status() == "toxic") {
                if (checkstatus == 0) { checkstatus = 8; enemy.set_hp(-1 * 1); }
                else { checkstatus -= 1; enemy.set_hp(-1 * 2); }
            }
            if (enemy.get_status() == "freeze") {
                if (checkstatus == 0) { checkstatus = 0; freezemob = 1; }
                else { checkstatus -= 1; enemy.set_hp(-1 * 2); }
            }
        }
        if (winorlose or enemy.get_hp() <= 0) { return 1; }
        if (inv.get_stat("hp") == 0 or inv.get_stat("mana") == 0) { return 0; }

        if (sheild) { sheild = 0; freezemob = 1; }
        if (freezemob == 0) { inv.set_stat("hp", -1 * enemy.get_damage()); }
        else { freezemob = 0; }

    }





    //return 1;
};