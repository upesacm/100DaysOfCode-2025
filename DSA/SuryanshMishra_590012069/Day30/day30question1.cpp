// 1. Clear the i-th Bit of a Number
// A problem that introduces bit clearing techniques and teaches how to unset specific bit positions using bitwise operations for selective bit manipulation.

// Given a number n and a bit position *i, clear the *i-th bit of the number (i.e., set it to 0) and return the new number using bitwise operations. This operation is fundamental in system programming and configuration management where you need to disable specific flags or reset particular bits without affecting other positions. The challenge involves understanding how to create appropriate masks and use bitwise operations to selectively clear bits while preserving the rest of the number.

// This teaches bit clearing and selective bit reset techniques that are essential for flag management and efficient bit-level configuration operations.

// Your task: Clear a specific bit position to 0 using bitwise operations while preserving all other bits.

// Examples
// Input:

// n = 7, i = 1

// Output:

// 5

// Input:

// n = 10, i = 3

// Output:

// 2
#include <iostream>
using namespace std;
int clearIthBit(int n, int i) {
    return n & ~(1 << i);
}
int main() {
int n1 = 7, i1 = 1;
cout << "Input: n = " << n1 << ", i = " << i1 << "\nOutput: " << clearIthBit(n1, i1) << endl;
int n2 = 10, i2 = 3;
cout << "Input: n = " << n2 << ", i = " << i2 << "\nOutput: " << clearIthBit(n2, i2) << endl;
return 0;
}