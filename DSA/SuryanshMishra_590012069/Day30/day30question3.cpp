// 3. Count Set Bits in an Integer
// A problem that teaches bit counting techniques and demonstrates how to analyze binary representations using efficient bit manipulation algorithms.

// Write a program to count the number of bits set to 1 in the binary representation of a given integer n using bit manipulation. This operation is fundamental in computer science and digital signal processing where you need to analyze binary patterns or *calculate Hamming weights. You can solve this using simple iteration, but try to think of *more efficient approaches using techniques like Brian Kernighan's algorithm or built-in population count functions.

// This teaches bit counting algorithms and binary analysis techniques that are essential for digital signal processing and efficient binary data analysis.

// Your task: Count the number of set bits in an integer using efficient bit manipulation techniques beyond simple iteration.

// Examples
// Input:

// n = 7

// Output:

// 3

// Input:

// n = 9

// Output:

// 2
#include <iostream>
using namespace std;
int countSetBits(int n) {
int count = 0;
while (n) {
n &= (n - 1);  // clear the rightmost set bit
count++;
    }
return count;
}
int main() {
int n1 = 7;
cout << "Input: n = " << n1 << "\nOutput: " << countSetBits(n1) << endl;
int n2 = 9;
cout << "Input: n = " << n2 << "\nOutput: " << countSetBits(n2) << endl;
return 0;
}