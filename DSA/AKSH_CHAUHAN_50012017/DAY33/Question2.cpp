#include <iostream>
using namespace std;

int turnOffRightmostSetBit(int n) {
    return n & (n - 1);
}
int main() {
    cout << turnOffRightmostSetBit(12) << endl; // Output: 8
    cout << turnOffRightmostSetBit(10) << endl; // Output: 8
    return 0;
}
