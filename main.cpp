#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;

struct Vehicle {
    string number;
    string type;
    int slot;
    time_t entryTime;
};

class ParkingLot {
private:
    int totalSlots;
    vector<bool> slots;
    vector<Vehicle> parkedVehicles;

public:
    ParkingLot(int n) : totalSlots(n) {
        slots.resize(n, false);
    }

    void parkVehicle(const string& number, const string& type) {
        for (int i = 0; i < totalSlots; ++i) {
            if (!slots[i]) {
                slots[i] = true;
                Vehicle v = {number, type, i + 1, time(0)};
                parkedVehicles.push_back(v);
                cout << "Vehicle parked at slot " << i + 1 << endl;
                generateReceipt(v, "ENTRY");
                return;
            }
        }
        cout << "Parking full!" << endl;
    }

    void removeVehicle(const string& number) {
        for (int i = 0; i < parkedVehicles.size(); ++i) {
            if (parkedVehicles[i].number == number) {
                int slotNum = parkedVehicles[i].slot - 1;
                slots[slotNum] = false;
                time_t exitTime = time(0);
                double duration = difftime(exitTime, parkedVehicles[i].entryTime) / 60; // in minutes
                int bill = calculateBill(duration);
                cout << "Vehicle removed from slot " << slotNum + 1 << endl;
                cout << "Time Parked: " << duration << " minutes" << endl;
                cout << "Total Bill: ₹" << bill << endl;
                generateReceipt(parkedVehicles[i], "EXIT", duration, bill);
                parkedVehicles.erase(parkedVehicles.begin() + i);
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }

    void showStatus() {
        cout << "\n--- Parking Lot Status ---\n";
        for (const auto& v : parkedVehicles) {
            cout << "Slot " << v.slot << ": " << v.type << " - " << v.number << endl;
        }
        cout << "Available slots: ";
        for (int i = 0; i < totalSlots; ++i) {
            if (!slots[i]) cout << i + 1 << " ";
        }
        cout << "\n--------------------------\n";
    }

    int calculateBill(double minutes) {
        double hours = minutes / 60.0;
        return ceil(hours * 10); // ₹10 per hour
    }

    void generateReceipt(const Vehicle& v, const string& action, double duration = 0, int bill = 0) {
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
        if (action == "EXIT") {
            file << "Duration       : " << duration << " minutes\n";
            file << "Total Bill     : ₹" << bill << "\n";
        }
        file << "==============================\n";

        file.close();
        cout << "Receipt saved to 'receipt.txt'\n";
    }
};

bool login() {
    string user, pass;
    cout << "=== Admin Login ===\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    return (user == "admin" && pass == "harsh123");
}

int main() {
    if (!login()) {
        cout << "Access Denied. Exiting...\n";
        return 0;
    }

    ParkingLot lot(5);
    int choice;
    string number, type;

    do {
        cout << "\n1. Park Vehicle\n2. Remove Vehicle\n3. Show Status\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter vehicle number: ";
                cin >> number;
                cout << "Enter vehicle type (Car/Bike): ";
                cin >> type;
                lot.parkVehicle(number, type);
                break;
            case 2:
                cout << "Enter vehicle number to remove: ";
                cin >> number;
                lot.removeVehicle(number);
                break;
            case 3:
                lot.showStatus();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}