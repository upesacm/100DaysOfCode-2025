#include <iostream>
using namespace std;
int main() {
    int a = 4, b = 7;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a = " << a << ", b = " << b;
    return 0;
}
