// 2. Get the i-th Bit of a Number
// A problem that demonstrates bit extraction techniques and teaches how to check specific bit positions using bitwise operations for binary data analysis.

// Given an integer n and a position i (0-indexed from the right), find whether the i-th bit is set (1) or not (0) using bitwise operations. This operation is fundamental in bit manipulation and binary data processing where you need to examine specific bit positions for flags, permissions, or data encoding. The challenge involves understanding how to isolate and check individual bits using masking and shifting operations.

// This introduces bit masking and position-based bit extraction techniques that are crucial for binary data analysis and bit-level data processing.

// Your task: Extract and check the value of a specific bit position using efficient bitwise masking operations.

// Examples
// Input:

// n = 5, i = 0
// Output:

// 1
// Input:

// n = 5, i = 1
// Output:

// 0
#include <iostream>
using namespace std;

// Function to get the i-th bit of number n
int getIthBit(int n, int i) {
    return (n & (1 << i)) ? 1 : 0;
}

int main() {
    int n1 = 5, i1 = 0;
    cout << "Input: n = " << n1 << ", i = " << i1 << endl;
    cout << "Output: " << getIthBit(n1, i1) << endl << endl;

    int n2 = 5, i2 = 1;
    cout << "Input: n = " << n2 << ", i = " << i2 << endl;
    cout << "Output: " << getIthBit(n2, i2) << endl;

    return 0;
}
