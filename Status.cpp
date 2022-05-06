#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Status.h"

using namespace std;

void Status(int atk, int def, int hp, int medicine, int current_hp) {//Output status of the player
    cout << endl;
    cout << "Below is your character status" << endl;
    cout << endl;
    cout << "ATK : " << atk << endl;
    cout << "DEF : " << def << endl;
    cout << "Current hp / HP : " << current_hp << " / " << hp << endl;
    if (medicine != 1) {
        medicine = 0;
    }
    cout << "Medicine (Maximum one per game): " << medicine << endl;
    cout << endl;
    char back = 'O';
    while (back != 'B' && back != 'b') {
        cout << "Press B/b to get back to initial interface" << endl;
        cout << endl;
        cout << "Input instruction: ";
        cin >> back;
        system("clear");
    }
}
