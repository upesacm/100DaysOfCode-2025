// 2. Toggle the i-th Bit of a Number
// A problem that demonstrates bit toggling techniques and teaches how to flip specific bit positions using bitwise operations for dynamic bit manipulation.

// Given a number n and an index *i, toggle the *i-th bit (if 0 set to 1, if 1 set to 0) using bit manipulation and return the updated value. This operation is commonly used in state management and toggle switches where you need to flip the state of specific bits dynamically. The challenge involves understanding how to use XOR operations effectively to toggle bits without knowing their current state, making it useful for implementing switches and state toggles.

// This introduces bit toggling and XOR-based bit manipulation techniques that are crucial for state management and dynamic bit switching operations.

// Your task: Toggle a specific bit position using XOR operations to flip its current state efficiently.

// Examples
// Input:

// n = 10, i = 1

// Output:

// 8

// Input:

// n = 5, i = 2

// Output:

// 1
#include <iostream>
using namespace std;
int toggleIthBit(int n, int i) {
    return n ^ (1 << i);
}
int main() {
int n1 = 10, i1 = 1;
cout << "Input: n = " << n1 << ", i = " << i1 << "\nOutput: " << toggleIthBit(n1, i1) << endl;
int n2 = 5, i2 = 2;
cout << "Input: n = " << n2 << ", i = " << i2 << "\nOutput: " << toggleIthBit(n2, i2) << endl;
return 0;
}