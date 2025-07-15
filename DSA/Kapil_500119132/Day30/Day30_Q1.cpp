#include <iostream>
using namespace std;

int clearBit(int n, int i) {
    int mask = ~(1 << i);
    return n & mask;
}

int main() {
    int n, i;
    cout << "Enter number (n): ";
    cin >> n;
    cout << "Enter bit position to clear (i): ";
    cin >> i;
    int result = clearBit(n, i);
    cout << "Result after clearing " << i << "-th bit: " << result << endl;
    return 0;
}
