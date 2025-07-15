#include <iostream>
using namespace std;

int toggleBit(int n, int i) {
    return n ^ (1 << i);
}

int main() {
    int n, i;
    cout << "Enter number (n): ";
    cin >> n;
    cout << "Enter bit position to toggle (i): ";
    cin >> i;
    int result = toggleBit(n, i);
    cout << "Result after toggling " << i << "-th bit: " << result << endl;
    return 0;
}
