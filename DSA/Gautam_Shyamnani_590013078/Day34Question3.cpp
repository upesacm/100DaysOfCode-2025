#include <iostream>
using namespace std;

bool isBinaryPalindrome(int n) {
    int left = 31; 
    while (((n >> left) & 1) == 0 && left > 0) left--; 

    int right = 0;

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
    int n = 9; 
    if (isBinaryPalindrome(n))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
