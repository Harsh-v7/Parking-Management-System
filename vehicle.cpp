#include "vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(string num, string t, int s) {
    number = num;
    type = t;
    slot = s;
}

void Vehicle::print() {
    cout << "Vehicle: " << number << " | Type: " << type << " | Slot: " << slot << endl;
}
