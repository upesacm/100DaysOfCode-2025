// 1. Check if a Number is Power of 2
// A problem that introduces bitwise logic and demonstrates how binary representations can simplify numerical checks.

// Given a number n, check if it is a power of 2 using bitwise operations. A power of 2 has only one bit set in its binary form. This problem is commonly used to teach efficient computation using bit manipulation and highlights the use of the n & (n - 1) trick to verify powers of two.

// This teaches binary logic, bitwise operations, and efficient numeric checks, which are essential for low-level programming and competitive coding.

// Your task: Determine if the given number is a power of 2 using bitwise operators only.

// Examples
// Input:

// n = 8
// Output:

// Yes
// Input:

// n = 10
// Output:

// No
#include <iostream>
using namespace std;
bool isPowerOfTwo(int n) {
return (n > 0) && ((n & (n - 1)) == 0);
}
int main() {
int n1 = 8;
cout << "Input: n = " << n1 << endl;
cout << "Output: " << (isPowerOfTwo(n1) ? "Yes" : "No") << endl;
int n2 = 10;
cout << "Input: n = " << n2 << endl;
cout << "Output: " << (isPowerOfTwo(n2) ? "Yes" : "No") << endl;
return 0;
}
