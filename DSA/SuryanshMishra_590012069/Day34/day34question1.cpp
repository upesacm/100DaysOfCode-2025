// 1. Add 1 to an Integer Using Bitwise
// A problem that introduces advanced arithmetic simulation using bitwise operations and teaches how to perform addition without traditional arithmetic operators.

// Add 1 to an integer n using only bitwise operators (no + or -). This problem demonstrates how fundamental arithmetic operations can be implemented using bit manipulation and is commonly used in low-level programming and embedded systems where arithmetic operations might be restricted or need optimization. The challenge involves understanding how binary addition works at the bit level, including handling carry propagation through multiple bit positions.

// This teaches bitwise arithmetic simulation and carry propagation techniques that are essential for low-level programming and efficient arithmetic implementations.

// Your task: Implement addition of 1 using only bitwise operations by simulating binary arithmetic carry propagation.

// Examples
// Input:

// n = 4
// Output:

// 5
// Input:

// n = 7
// Output:

// 8
#include <iostream>
using namespace std;
int addOne(int n) {
int carry = 1;
while (carry != 0) {
int sum = n ^ carry;  // Sum without carry
carry = (n & carry) << 1;  // Calculate carry
n = sum;  // Update n
if (carry == 0) {
break;  // If no carry, we can exit the loop
}
}
return n;
}