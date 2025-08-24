#include <iostream>
using namespace std;

bool isBinaryPalindrome(unsigned int n) {
    int left = sizeof(n) * 8 - 1;  // Start from MSB
    int right = 0;                // Start from LSB

    while (left > right) {
        bool leftBit = (n >> left) & 1;
        bool rightBit = (n >> right) & 1;

        if (leftBit != rightBit)
            return false;

        left--;
        right++;
    }

    return true;
}
int main() {
    int n1 = 9;  // binary: 1001
    int n2 = 10; // binary: 1010

    cout << (isBinaryPalindrome(n1) ? "Yes" : "No") << endl; // Output: Yes
    cout << (isBinaryPalindrome(n2) ? "Yes" : "No") << endl; // Output: No

    return 0;
}