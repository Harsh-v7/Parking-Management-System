#include "billing.h"
#include <cmath>

int calculateBill(double minutes) {
    double hours = minutes / 60.0;
    return ceil(hours * 10);  // ₹10 per hour
}
