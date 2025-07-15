// 1. Check if a Number is Even or Odd Using Bit Manipulation
// A problem that introduces fundamental bitwise operations and teaches how to determine number parity using bit-level analysis instead of arithmetic operations.

// You are given an integer n. Using bitwise operations, determine if the number is even or odd. Do not use the modulus operator. This problem demonstrates how bit manipulation can replace traditional arithmetic operations and is commonly used in low-level programming and performance-critical applications where bitwise operations are faster than division or modulus operations. The key insight is that the least significant bit (LSB) determines the parity of any number.

// This teaches bit-level number analysis and bitwise parity detection techniques that are essential for low-level programming and efficient arithmetic operations.

// Your task: Determine if a number is even or odd using only bitwise operations without arithmetic operators.

// Examples
// Input:

// 4
// Output:

// Even
// Input:

// 7
// Output:

// Odd
#include <iostream>
using namespace std;

void checkEvenOrOdd(int n) {
    if (n & 1)
        cout << "Odd" << endl;
    else
        cout << "Even" << endl;
}

int main() {
    int n1 = 4;
    cout << "Input: " << n1 << "\nOutput: ";
    checkEvenOrOdd(n1);

    int n2 = 7;
    cout << "Input: " << n2 << "\nOutput: ";
    checkEvenOrOdd(n2);

    return 0;
}
