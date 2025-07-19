#include <iostream>
using namespace std;

bool haveOppositeSigns(int a, int b) {
    return (a ^ b) < 0;
}

int main() {
    int a = 2, b = -3;

    if (haveOppositeSigns(a, b)) {
        cout << "Yes, " << a << " and " << b << " have opposite signs." << endl;
    } else {
        cout << "No, " << a << " and " << b << " have the same sign." << endl;
    }

    return 0;
}
