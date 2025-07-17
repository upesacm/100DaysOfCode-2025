// 3. Find XOR of All Numbers in an Array
// An introductory problem in bitwise accumulation that builds a strong foundation for many XOR-based problems.

// Write a function to compute the XOR of all elements in the array. XOR acts like a parity check, and this concept is frequently used in encryption, checksum validation, and binary data processing.

// This teaches bitwise reduction techniques, XOR properties, and is a stepping stone toward advanced XOR-based algorithms.

// Your task: Return the result of XORing all numbers in the array.

// Examples
// Input:

// arr = [1, 2, 3]
// Output:

// 0
// Input:

// arr = [4, 5, 6]
// Output:

// 7
#include <iostream>
#include <vector>
using namespace std;
int main() {
int n;
cin >> n; // Number of elements
vector<int> arr(n);
for (int i = 0; i < n; ++i)
cin >> arr[i];
int xorResult = 0;
for (int num : arr)
xorResult ^= num;
cout << xorResult << endl;
return 0;
}