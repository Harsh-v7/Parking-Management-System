#include "auth.h"
#include <iostream>
#include <string>
using namespace std;

bool login() {
    string user, pass;
    cout << "=== Admin Login ===\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    return (user == "admin" && pass == "harsh123");
}