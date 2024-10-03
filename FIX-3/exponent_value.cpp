//Make the code work for for negatice exponent value
#include <iostream>
using namespace std;

float positiveExponent(int base, int exp) {
    float result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

float exponent(int base, int exp) {
    if (exp >= 0) {
        return positiveExponent(base, exp);
    } else {
        // Calculate base^exp as 1 / (base^-exp)
        return 1.0 / positiveExponent(base, -exp);
    }
}

int main() {
    int base = 2;
    int positiveExp = 3;
    int negativeExp = -2;

    cout << base << "^" << positiveExp << " = " << exponent(base, positiveExp) << endl;
    cout << base << "^" << negativeExp << " = " << exponent(base, negativeExp) << endl;

    return 0;
}
