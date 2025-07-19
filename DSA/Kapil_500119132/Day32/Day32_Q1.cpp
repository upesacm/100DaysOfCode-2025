#include <iostream>
using namespace std;
int addOne(int n) {
    int mask = 1;
    while (n & mask) {
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
    int result = addOne(n);
    cout << "Result after adding 1: " << result << endl;
    return 0;
}
