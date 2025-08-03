#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfTwo(n))
        cout << "Yes, " << n << " is a power of 2.\n";
    else
        cout << "No, " << n << " is not a power of 2.\n";

    return 0;
}
