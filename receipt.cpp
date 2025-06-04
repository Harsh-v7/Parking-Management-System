#include <fstream>
#include <ctime>
#include "vehicle.h"

void generateReceipt(const Vehicle& v, const string& action) {
    ofstream file("receipt.txt", ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);

    file << "\n==============================\n";
    file << "   PARKING RECEIPT - " << action << "\n";
    file << "------------------------------\n";
    file << "Vehicle Number : " << v.number << "\n";
    file << "Vehicle Type   : " << v.type << "\n";
    file << "Slot Number    : " << v.slot << "\n";
    file << "Time           : " << dt;
    file << "==============================\n";

    file.close();
}
