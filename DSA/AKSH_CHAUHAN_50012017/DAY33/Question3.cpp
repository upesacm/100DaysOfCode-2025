#include <iostream>
using namespace std;

int isolateRightmostSetBit(int n) {
    return n & -n;
}
int main() {
    cout << isolateRightmostSetBit(10) << endl; // Output: 2
    cout << isolateRightmostSetBit(12) << endl; // Output: 4
    return 0;
}
