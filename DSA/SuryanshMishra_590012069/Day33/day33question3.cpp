// 3. Isolate the Rightmost Set Bit
// This problem helps you extract the rightmost 1-bit from a number while resetting all other bits — a useful technique in many binary search optimizations, bit masks, and hardware manipulation routines.

// Given an integer n, isolate and return only the rightmost set bit as a new number (all other bits should be 0).

// This teaches bit masking, two’s complement logic, and bitfield extraction.

// Your task: Isolate the rightmost set bit of the number.

// Examples
// Input:

// n = 10
// Output:

// 2
// Input:

// n = 12
// Output:

// 4
#include <iostream>
using namespace std;
int main() {
int n;
cin >> n;
int result = n & -n;  // Isolate the rightmost set bit
cout << result << endl;
return 0;
}