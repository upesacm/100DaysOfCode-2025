#include <iostream>
using namespace std;

// Subtracts 1 from n using only bitwise operators
int subtractOne(int n) {
    int mask = 1;
    while ((n & mask) == 0) {
        n = n ^ mask;
        mask <<= 1;
    }
    n = n ^ mask;
    return n;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = subtractOne(n);
    cout << "Result after subtracting 1: " << result << endl;
    return 0;
}
