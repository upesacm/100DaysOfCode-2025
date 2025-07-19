// 3. Check if Binary Representation of a Number is Palindrome
// A problem that teaches binary pattern analysis and demonstrates how to check symmetry in binary representations using bit manipulation techniques.

// Given a number n, check whether its binary representation is a palindrome (i.e., reads the same forwards and backwards). This problem combines bit manipulation with palindrome detection and is commonly used in digital signal processing and pattern recognition where you need to analyze binary symmetry. The challenge involves efficiently comparing bits from both ends of the binary representation without converting to strings.

// This teaches binary symmetry detection and bit-level palindrome checking techniques that are essential for pattern recognition and efficient binary data analysis.

// Your task: Check if a number's binary representation is palindromic using efficient bit manipulation without string conversion.

// Examples
// Input:

// n = 9 (binary: 1001)
// Output:

// Yes
// Input:

// n = 10 (binary: 1010)
// Output:

// No
#include <iostream>
using namespace std;
bool isPalindrome(int n) {
int reversed = 0;
int original = n;
while (n > 0) {
reversed = (reversed << 1) | (n & 1);
n >>= 1;
}
return original == reversed;
}