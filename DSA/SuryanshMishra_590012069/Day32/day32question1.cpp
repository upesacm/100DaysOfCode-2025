// 1. Swap Two Numbers Without Temporary Variable
// A classic bitwise trick that shows how XOR can be used to swap values without using extra memory. This problem reinforces the concept that XOR has properties which make it suitable for in-place data manipulation.

// Given two integers a and b, swap their values using bitwise XOR without using any temporary variable. This is a common interview question to test your understanding of bitwise fundamentals.

// This teaches XOR logic, in-place data manipulation, and memory-efficient algorithms, useful for embedded systems and interview prep.

// Your task: Swap two integers using only bitwise operators.

// Examples
// Input:

// a = 4, b = 7
// Output:

// a = 7, b = 4
// Input:

// a = 1, b = 2
// Output:

// a = 2, b = 1
#include <iostream>
using namespace std;
int main() {
int a, b;
cin >> a >> b;
a = a ^ b;
b = a ^ b;
a = a ^ b;
cout << a << " " << b << endl;
return 0;
}