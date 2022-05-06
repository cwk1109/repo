#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Boss.h"

using namespace std;

void boss(int& atk, int& def, int& hp, int& current_hp, int& level, char character, int& medicine) {//manage fight with boss and ouput won or lost at the end
    system("clear");
    cout << endl << "Here is the boss" << endl;
    int mp = 0;
    int monster_atk = 25, monster_def = 10, monster_hp = 100;
    current_hp = hp;
    int check_medicine;
    while (monster_hp != 0 and current_hp != 0) {
        cout << endl;
        cout << "Monster Status : " << endl;
        cout << "Monster atk : " << monster_atk << endl;
        cout << "Monster def : " << monster_def << endl;
        cout << "Monster HP (right now) : " << monster_hp << endl << endl;
        cout << "Your Status:" << endl;
        cout << "Your atk : " << atk << endl;
        cout << "Your def : " << def << endl;
        cout << "Your HP (right now) : " << current_hp << '/' << hp << endl;
        cout << "Your MP (right now) : " << mp << "/30" << endl;
        cout << "Please folow the below instruction to slay the monster" << endl;
        cout << endl;
        cout << "Option 1, press 'a' key: Normal attack" << endl;
        cout << "Option 2, press 'p' key: Masterstroke (Only can be used while mp = 100)" << endl;
        char opt;
        cout << endl;
        cout << "Input instruction: ";
        cin >> opt;
        system("clear");
        if (opt == 'a') {
            monster_hp = monster_hp - atk + monster_def;
            if (monster_hp <= 0) {
                monster_hp = 0;
                system("clear");
            }
            else {
                monster_hp = monster_hp - atk + monster_def;
                current_hp = current_hp + def - monster_atk;
                if (current_hp <= 0) {
                    current_hp = 0;
                    check_medicine = hp;
                    hp = 0;
                }
                if (mp < 30) {
                    mp += 10;
                }
            }
        }
        else if (opt == 'p') {
            if (mp == 30) {
                monster_hp = monster_hp - atk * 2 + monster_def;
                mp = -10;
                current_hp = current_hp + def - monster_atk;
                if (monster_hp <= 0) {
                    monster_hp = 0;
                }
                if (current_hp <= 0) {
                    current_hp = 0;
                    check_medicine = hp;
                    hp = 0;
                }
                if (mp < 30) {
                    mp += 10;
                }
            }
            else {
                cout << '\n' << "MP is not enough!" << endl;
            }
        }
        else {
            cout << endl << "Invalid Input" << endl;
        }
    }
    if (monster_hp == 0) {
        cout << endl;
        cout << "You Won" << endl;
        hp += 1;
        level += 1;
    }
    else {
        cout << endl;
        char Y_N;
        if (medicine == 1) {//check medicine
            cout << "You have 1 medicine, would you like to dink? If yes, input insrtuction 'Y'." << endl;
            cout << endl << "Input instruction : ";
            cin >> Y_N;
            if (Y_N == 'Y') {
                hp = check_medicine;
                current_hp = hp;
                medicine += 1;
            }
            else {
                cout << "You are dead." << endl;
            }
        }
        else {
            cout << "You are dead." << endl;
        }
    }

}
