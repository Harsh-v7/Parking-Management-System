# Parking Management System

This is a command-line based Parking Management System built in C++.
It includes admin login, billing calculation, receipt generation, and vehicle tracking.

## Features
- Admin authentication
- Park and remove vehicles
- Duration tracking
- Billing at ₹10 per hour
- Receipts saved in `receipt.txt`

## 🛠️ Tech Stack
- C++
- Standard Library (iostream, fstream, vector, ctime)

## 🗂️ File Structure
```
parking-management-system-advanced/
├── main.cpp
├── vehicle.cpp
├── vehicle.h
├── billing.cpp
├── billing.h
├── auth.cpp
├── auth.h
├── receipt.txt
├── Makefile
└── README.md
```

## 🧾 How to Compile and Run
Option 1: Using `make`
```bash
make
./parking_system
```

Option 2: Using g++ directly
```bash
g++ main.cpp vehicle.cpp billing.cpp auth.cpp -o parking_system
./parking_system
```

## 📥 Output
All receipts will be appended in:
```
receipt.txt
```

---
> Created by Harsh Verma
