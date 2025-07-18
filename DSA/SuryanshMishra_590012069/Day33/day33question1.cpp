// 1. Check if Two Numbers Have Opposite Signs
// A fundamental bitwise check that determines if two integers have opposite signs by using the sign bit. This is commonly used in systems programming, signal handling, and even game logic.

// Given two integers a and b, use bitwise operations to check if they have opposite signs. This works because the sign bit (most significant bit) will differ if the signs are different.

// This teaches sign bit manipulation, XOR/sign checking, and is useful in low-level debugging or optimization.

// Your task: Check whether two numbers have opposite signs using bitwise operations.

// Examples
// Input:

// a = 2, b = -3
// Output:

// True
// Input:

// a = -4, b = -5
// Output:

// False
#include <iostream>
using namespace std;
int main() {
int a, b;
cin >> a >> b;
bool oppositeSigns = (a ^ b) < 0;
cout << (oppositeSigns ? "True" : "False") << endl;
return 0;
}