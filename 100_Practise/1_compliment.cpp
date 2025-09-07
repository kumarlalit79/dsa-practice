#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Function to convert decimal to binary string
string decimalToBinary(int n) {
    string binary = "";
    if (n == 0) return "0";

    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n = n / 2;
    }
    return binary;
}

// Function to flip bits (1's complement)
string onesComplement(string binary) {
    string complement = "";
    for (char bit : binary) {
        if (bit == '0') complement += '1';
        else complement += '0';
    }
    return complement;
}

// Function to convert binary string to decimal
int binaryToDecimal(string binary) {
    int result = 0;
    int power = 0;

    // Start from rightmost digit
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            result += pow(2, power);
        }
        power++;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    string binary = decimalToBinary(n);
    string flipped = onesComplement(binary);
    int complement = binaryToDecimal(flipped);

    cout << "Binary of " << n << " is: " << binary << endl;
    cout << "Flipped binary is: " << flipped << endl;
    cout << "Complement is: " << complement << endl;

    return 0;
}
