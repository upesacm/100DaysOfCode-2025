#include <iostream>
using namespace std;

void checkEvenOdd(int n) {
    if (n & 1) // check LSB
        cout << "Odd" << endl;
    else
        cout << "Even" << endl;
}
