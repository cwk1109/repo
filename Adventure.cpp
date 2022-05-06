#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Adventure.h"
#include "Boss.h"

using namespace std;

void Adventure(int& atk, int& def, int& hp, int& current_hp, int& level, char character, int& medicine) {//manage adventure part of the game and ouputs user interfcae
    int monster_array[10][3] = { {10,0,30}, {12,3,30}, {20,0,35}, {20,0,50} };
    char play_back;
    int times = 0;
    cout << endl;
    cout << "Input the instruction C/c to continue or B/b to get back to the initial interface or S/s to Save current progress" << endl;
    cout << endl;
    cout << "Input instruction: ";
    cin >> play_back;
    int check_medicine;
    while (times < 10 and level != 4) {
        if (play_back == 'B' || play_back == 'b') {
            system("clear");
            times = 11;
        }
        else {
            if (play_back == 'C' || play_back == 'c') {
                system("clear");
                cout << endl;
                cout << "Here is level " << level + 1 << endl;
                cout << "The monster you gonna fight is monster " << level + 1 << endl;


                int monster_hp = monster_array[level][2];
                int mp = 0;
                while (monster_array[level][2] != 0 and hp != 0) {
                    cout << endl;
                    cout << "Monster Status : " << endl;
                    cout << "Monster atk : " << monster_array[level][0] << endl;
                    cout << "Monster def : " << monster_array[level][1] << endl;
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
                        monster_hp = monster_array[level][2] - atk + monster_array[level][1];
                        if (monster_hp <= 0) {
                            monster_hp = 0;
                            monster_array[level][2] = 0;
                            system("clear");
                        }
                        else {
                            monster_hp = monster_array[level][2] - atk + monster_array[level][1];
                            monster_array[level][2] = monster_array[level][2] - atk + monster_array[level][1];
                            current_hp = current_hp + def - monster_array[level][0];
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
                            monster_hp = monster_array[level][2] - atk * 2 + monster_array[level][1];
                            monster_array[level][2] = monster_array[level][2] - atk * 2 + monster_array[level][1];
                            mp = -10;
                            current_hp = current_hp + def - monster_array[level][0];
                            if (monster_hp <= 0) {
                                monster_hp = 0;
                                monster_array[level][2] = 0;
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
                    char selection;
                    cout << "The monster has been slayed" << endl;
                    char option = 'O';
                    int i = 0;
                    int pass = 0;
                    int atk_plus, def_plus, hp_plus;
                    while (option != 'A' && option != 'B') {//get buff if monster has been slayed down
                        if (medicine == 0) {
                            cout << endl;
                            cout << "Option A : Choose one of three selection below : " << endl;
                            cout << "atk + (3 to 7), def + (2 to 4) or hp + (10 to 20)" << endl << endl;
                            cout << "Option B : Lucky draw (You have 50% to get the medicine, if not you can only choose one of (atk, def and hp) increase 1.)" << endl;
                            cout << endl << "Input instruction : ";
                            cin >> option;
                        }
                        else {
                            option = 'A';
                        }
                        if (option == 'A') {//choose medicine
                            srand(time(0));
                            atk_plus = rand() % 5 + 3, def_plus = rand() % 3 + 2, hp_plus = rand() % 11 + 10;
                        }
                        else {
                            if (option == 'B') {
                                srand(time(0));
                                medicine = rand() % 2;
                                if (medicine == 1) {
                                    cout << "Congraduation ! ! ! You get the medicine x 1." << endl;
                                    pass = 1;
                                }
                                else {
                                    cout << endl << "You do not get the medicine, you can choose one of (atk, def and hp) increase 1." << endl;
                                    atk_plus = 1, def_plus = 1, hp_plus = 1;
                                }
                            }
                            else {
                                system("clear");
                                cout << endl;
                                cout << "Invalid Input" << endl;
                            }
                        }
                    }
                    while (i != -1) {//choose buff
                        if (pass == 0) {
                            cout << endl << "choose A, B or C" << endl;
                            cout << "A : atk + " << atk_plus << endl << "B : def + " << def_plus << endl << "C : hp + " << hp_plus << endl << endl;
                            cout << "Input instruction: ";
                            cin >> selection;
                            switch (selection) {
                            case'A':
                                atk += atk_plus;
                                i = -1;
                                break;
                            case'B':
                                def += def_plus;
                                i = -1;
                                break;
                            case'C':
                                hp += hp_plus;
                                current_hp += hp_plus;
                                i = -1;
                                break;
                            default:
                                system("clear");
                                cout << endl << "Invalid Input" << endl;
                            }
                        }
                        pass = 0;
                        i = -1;
                    }
                    if (level == 3) {
                        char play_back = 'O';
                        int times = 0;
                        while (times < 10) {
                            cout << "Input the instruction C/c to continue or B/b to get back to the initial interface or S/s to Save current progress" << endl;
                            cout << endl;
                            cout << "Input instruction: ";
                            cin >> play_back;
                            if (play_back == 'B' || play_back == 'b') {
                                system("clear");
                                times = 10;
                            }
                            else if (play_back == 'S' || play_back == 's') {
                                ofstream fout("data.txt");
                                fout << atk << '\n' << def << '\n' << hp << '\n' << current_hp << '\n' << level << '\n' << medicine;
                                fout.close();
                                system("clear");
                                cout << "Saved Succesfully!" << endl;
                                cout << "Input the instruction C/c to continue or B/b to get back to the initial interface or S/s to Save current progress" << endl;
                                cout << endl;
                                cout << "Input instruction: ";
                                cin >> play_back;
                            }
                            else {
                                if (play_back == 'C' || play_back == 'c') {
                                    times = 10;
                                    system("clear");
                                    cout << endl;
                                    boss(atk, def, hp, current_hp, level, character, medicine);//call function boss
                                }
                            }
                            times++;
                        }
                    }
                    level += 1;
                    if (level < 4) {
                        Adventure(atk, def, hp, current_hp, level, character, medicine);//recursion
                    }
                }
                else {
                    cout << endl;
                    char Y_N;
                    if (medicine == 1) {
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

                if (level != 4) {
                    times = 11;
                }
            }
            else if (play_back == 'S' || play_back == 's') {
                ofstream fout ("data.txt");
                fout << atk << '\n' << def << '\n' << hp << '\n' << current_hp << '\n' << level << '\n' << medicine;
                fout.close();
                system("clear");
                cout << "Saved Succesfully!" << endl;
                cout << "Input the instruction C/c to continue or B/b to get back to the initial interface or S/s to Save current progress" << endl;
                cout << endl;
                cout << "Input instruction: ";
                cin >> play_back;
            }
            else {
                system("clear");
                cout << endl;
                cout << "Wrong input instruction, please inut again" << endl;
                cout << endl;
                cout << "Input the instruction C/c to continue or B/b to get back to the initial interface or S/s to Save current progress" << endl;
                cout << endl;
                cout << "Input instruction: ";
                cin >> play_back;
                times++;
            }
        }
    }
    if (times == 10) {
        system("clear");
        cout << "10 times invalid input, return to initial interface" << endl;
    }
}


