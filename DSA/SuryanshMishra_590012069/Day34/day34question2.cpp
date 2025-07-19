// 2. Subtract 1 from an Integer Using Bitwise
// A problem that demonstrates subtraction simulation using bitwise operations and teaches how to perform decrement operations without traditional arithmetic operators.

// Subtract 1 from a given number n using only bitwise operations, without using the subtraction operator. This operation is fundamental in bit manipulation and low-level programming where you need to implement arithmetic operations using only logical operations. The challenge involves understanding how binary subtraction works, including handling borrow operations when subtracting from numbers with trailing zeros.

// This introduces bitwise subtraction simulation and borrow handling techniques that are crucial for arithmetic operation implementation and low-level mathematical computations.

// Your task: Implement subtraction of 1 using only bitwise operations by simulating binary arithmetic borrow propagation.

// Examples
// Input:

// n = 5
// Output:

// 4
// Input:

// n = 8
// Output:

// 7
#include <iostream>
using namespace std;
int subtractOne(int n) {
int borrow = 1;
while (borrow != 0) {
int diff = n ^ borrow;  // Difference without borrow
borrow = ((~n) & borrow) << 1;  // Calculate borrow
n = diff;  // Update n
if (borrow == 0) {
break;  // If no borrow, we can exit the loop
}
}
return n;
}