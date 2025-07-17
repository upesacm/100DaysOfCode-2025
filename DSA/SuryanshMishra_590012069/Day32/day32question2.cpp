// 2. Find the Only Non-Repeating Element
// A problem that leverages XOR's property where identical bits cancel out, helping you find a unique element in a set of duplicates.

// Given an array of integers where every element appears twice except for one, find the unique non-repeating element using bitwise XOR. This is efficient and requires no additional memory, unlike frequency maps.

// This teaches XOR aggregation, data deduplication, and memory-optimized searching, which are highly valuable for competitive programming and low-memory devices.

// Your task: Find the single non-repeating number using XOR.

// Examples
// Input:

// arr = [2, 3, 2]
// Output:

// 3
// Input:

// arr = [5, 1, 1, 5, 7]
// Output:

// 7
#include <iostream>
#include <vector>
using namespace std;
int main() {
int n;
cin >> n; // Number of elements in the array
vector<int> arr(n);    
for (int i = 0; i < n; ++i)
cin >> arr[i];
int result = 0;
for (int i = 0; i < n; ++i)
result ^= arr[i];
cout << result << endl;
return 0;
}