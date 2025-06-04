// vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
public:
    string number;
    string type;
    int slot;

    Vehicle(string num, string t, int s);
    void print();
};

#endif
