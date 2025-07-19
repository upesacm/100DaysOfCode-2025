#include <iostream>
using namespace std;

int turnOffRightmostSetBit(int n) {
   
    return n & (n - 1);
}

int main() {
    int n = 12;

    cout << "Original number: " << n << endl;
    cout << "After turning off the rightmost set bit: " << turnOffRightmostSetBit(n) << endl;

    return 0;
}
