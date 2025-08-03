// 3. Divide a Number by 2 Using Bitwise
// A problem that illustrates the use of right shift operations to perform integer division efficiently.

// Given a number n, write a program to divide it by 2 using bitwise shift operators. This operation discards the decimal part, making it a fast alternative to division in certain applications like graphics, embedded systems, or real-time computations.

// This teaches bitwise right shifting and low-level arithmetic operations that are essential for speed-critical systems and resource-constrained environments.

// Your task: Divide the number by 2 using bitwise operators (ignore decimals).

// Examples
// Input:

// n = 10
// Output:

// 5
// Input:

// n = 9
// Output:

// 4
#include <iostream>
using namespace std;
int divideByTwo(int n) {
return n >> 1;
}
int main() {
int n1 = 10;
cout << "Input: n = " << n1 << endl;
cout << "Output: " << divideByTwo(n1) << endl;
int n2 = 9;
cout << "Input: n = " << n2 << endl;
cout << "Output: " << divideByTwo(n2) << endl;
return 0;
}