#include <iostream>
using namespace std;

// Checks if binary representation of n is a palindrome
bool isBinaryPalindrome(unsigned int n) {
    unsigned int bits = sizeof(n) * 8;
    unsigned int left = bits - 1;
    unsigned int right = 0;

    // Trim leading zeros
    while (left > 0 && ((n >> left) & 1) == 0) left--;

    while (left > right) {
        if (((n >> left) & 1) != ((n >> right) & 1))
            return false;
        left--;
        right++;
    }
    return true;
}

int main() {
    unsigned int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isBinaryPalindrome(n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
