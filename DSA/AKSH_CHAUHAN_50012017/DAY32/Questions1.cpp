#include <iostream>
using namespace std;

void swapNumbers(int &a, int &b) {
    a = a ^ b;
    b = a ^ b; 
    a = a ^ b; 
}
int main() {
    int a = 4, b = 7;
    swapNumbers(a, b);
    cout << "a = " << a << ", b = " << b << endl; 
    return 0;
}
