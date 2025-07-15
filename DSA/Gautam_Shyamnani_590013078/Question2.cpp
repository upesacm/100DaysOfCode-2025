#include <iostream>
using namespace std;

int toggleBit(int n, int i) {
    return n ^ (1 << i);  
}

int main() {
    cout << toggleBit(10, 1) << endl;  
    cout << toggleBit(5, 2) << endl;   
    return 0;
}
