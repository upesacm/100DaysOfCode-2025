// 3. Set the i-th Bit of a Number
// A problem that teaches bit modification techniques and demonstrates how to set specific bit positions using bitwise operations for binary data manipulation.

// You are given an integer n and a position i. Set the i-th bit (0-indexed from right) of the number to 1 using bitwise operations and return the new number. This operation is commonly used in system programming and flag management where you need to enable specific bits for configuration settings, permissions, or status indicators. The challenge involves understanding how to modify individual bits without affecting other bit positions.

// This teaches bit setting and selective bit modification techniques that are essential for system programming and efficient bit-level data manipulation.

// Your task: Set a specific bit position to 1 using bitwise operations while preserving all other bits.

// Examples
// Input:

// n = 5, i = 1
// Output:

// 7
// Input:

// n = 8, i = 2
// Output:

// 12
#include <iostream>
using namespace std;

// Function to set the i-th bit of number n
int setIthBit(int n, int i) {
    return n | (1 << i);
}

int main() {
    int n1 = 5, i1 = 1;
    int result1 = setIthBit(n1, i1);
    cout << "Input: n = " << n1 << ", i = " << i1 << endl;
    cout << "Output: " << result1 << endl << endl;

    int n2 = 8, i2 = 2;
    int result2 = setIthBit(n2, i2);
    cout << "Input: n = " << n2 << ", i = " << i2 << endl;
    cout << "Output: " << result2 << endl;

    return 0;
}
