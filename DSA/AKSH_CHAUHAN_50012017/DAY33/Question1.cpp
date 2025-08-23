#include <iostream>
using namespace std;

bool haveOppositeSigns(int a, int b) {
    return (a ^ b) < 0;
}
int main() {
    int a = 2, b = -3;
    cout << (haveOppositeSigns(a, b) ? "True" : "False") << endl; // Output: True

    a = -4, b = -5;
    cout << (haveOppositeSigns(a, b) ? "True" : "False") << endl; // Output: False
    return 0;
}
