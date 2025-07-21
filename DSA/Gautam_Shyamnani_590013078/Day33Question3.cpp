#include <iostream>
using namespace std;

int isolateRightmostSetBit(int n) {
    return n & -n;
}

int main() {
    int n = 10;

    cout << "Original number: " << n << endl;
    cout << "Rightmost set bit isolated: " << isolateRightmostSetBit(n) << endl;

    return 0;
}
