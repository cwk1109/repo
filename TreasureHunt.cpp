#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Boss.h"
#include "Adventure.h"
#include "Status.h"

using namespace std;

int main() {
    ifstream fin;//file management
    fin.open("data.txt");
    cout << endl;
    int atk, def, hp = 0, medicine = 0;
    int current_hp = hp;
    char character, game_instruction = 'O';
    int level = 0;
    cout << "Please name your character" << endl;
    cout << endl;
    cout << "Name: ";
    string* n = new string;//dynamic memory management
    cin >> *n;
    system("clear");
    int i = 0;
    while (i != -1) {
        cout << endl;
        cout << "Please select your own character (input A or B) or Load previous data (input L): " << endl;
        cout << endl;
        cout << (" A (atk = 15, def = 8, hp = 40):") << endl;
        cout << (" B (atk = 8, def = 10, hp = 60):") << endl;
        cout << endl;
        cout << "Input instruction: ";
        cin >> character;
        system("clear");
        ifstream fin("data.txt");
        switch (character) {

        case 'A':
            atk = 15, def = 8, hp = 40;
            i = -1;
            current_hp = hp;
            break;
        case 'B':
            atk = 8, def = 10, hp = 60;
            i = -1;
            current_hp = hp;
            break;
        case 'L':
            if (fin.fail()) {
                cout << "Not saved yet!" << endl;
            }
            else {
                fin >> atk >> def >> hp >> current_hp >> level >> medicine;
            }
            i = -1;
            break;
        default:
            cout << endl << "Invalid Input" << endl;

        }
        fin.close();
    }

    cout << endl;
    cout << "Below is your initial character status (Only show once)" << endl;
    cout << endl;
    cout << "Name: " << *n << endl;
    cout << "Character: " << character << endl;
    cout << "ATK: " << atk << endl;
    cout << "DEF: " << def << endl;
    cout << "Current hp / HP : " << current_hp << " / " << hp << endl;

    while (game_instruction != 'Q') {
        cout << endl;
        cout << "Please input the instruction below: " << endl;
        cout << endl;
        if (level <= 3) {
            cout << "Press 'A' key : Adventure (Level " << level + 1 << " )" << endl;
        }
        else {
            if (level == 4) {
                cout << "Press 'A' key : Adventure (BOSS)" << endl;
            }
            else {
                cout << "Press 'A' key : Adventure (ALREADY PASS)" << endl;
            }
        }
        cout << "Press 'S' key : Status" << endl;
        cout << "Press 'Q' key : Leave" << endl;
        cout << endl;
        cout << "Input instruction: ";
        cin >> game_instruction;
        system("clear");
        if (game_instruction == 'A') {
            if (hp == 0) {
                cout << endl << "You are dead, you can not get into this motion again" << endl;
            }
            else if (level < 4) {
                Adventure(atk, def, hp, current_hp, level, character, medicine);//call function Adventure
            }
            else {
                if (level == 4) {
                    boss(atk, def, hp, current_hp, level, character, medicine);//call function Boss
                }
                else {
                    cout << endl << "You has already slayed the boss, please press Q to leave. " << endl;
                }
            }
        }
        if (game_instruction == 'S') {
            Status(atk, def, hp, medicine, current_hp);//call function Status
        }
        if (game_instruction == 'Q') {
            cout << endl;
            cout << "END" << endl;
            cout << endl;
        }
        if (game_instruction == 'L') {
            ifstream fin ("data.txt");
            if (fin.fail()) {
                cout << "Not saved yet!" << endl;
                exit(1);
            }
            else {
                fin >> atk >> def >> hp >> current_hp >> level >> medicine;
            }
            fin.close();
        }
    }
    delete(n);
    return 0;
}
