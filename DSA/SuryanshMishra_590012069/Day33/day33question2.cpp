// 2. Turn Off the Rightmost Set Bit
// A popular bit manipulation technique that clears the rightmost set bit (1) from a number. This is often used in bit counting algorithms or efficient looping.

// Given an integer n, use bitwise operations to turn off its rightmost 1-bit.

// This teaches AND with (n - 1), a classic trick used in Hamming weight, submask enumeration, and power-of-two logic.

// Your task: Clear the rightmost set bit of the number.

// Examples
// Input:

// n = 12
// Output:

// 8
// Input:

// n = 10
// Output:

// 8
#include <iostream>
using namespace std;
int main() {
int n;
cin >> n;
int result = n & (n - 1);
cout << result << endl;
return 0;
}