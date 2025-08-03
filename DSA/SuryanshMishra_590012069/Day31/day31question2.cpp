// 2. Multiply a Number by 2 Using Bitwise
// A classic bit manipulation exercise that demonstrates how to use left shift operations to perform multiplication efficiently.

// Given an integer n, write a program to multiply it by 2 using only bitwise operators. This is equivalent to shifting all bits to the left by one position, a common low-level optimization technique used in systems and embedded programming.

// This teaches bitwise left shifting and efficient arithmetic tricks that are useful in performance-critical applications.

// Your task: Multiply the given number by 2 using bitwise operations.

// Examples
// Input:

// n = 3
// Output:

// 6
// Input:

// n = 7
// Output:

// 14
#include <iostream>
using namespace std;
int multiplyByTwo(int n) {
    return n << 1;
}
int main() {
int n1 = 3;
cout << "Input: n = " << n1 << endl;
cout << "Output: " << multiplyByTwo(n1) << endl;
int n2 = 7;
cout << "Input: n = " << n2 << endl;
cout << "Output: " << multiplyByTwo(n2) << endl;
return 0;
}