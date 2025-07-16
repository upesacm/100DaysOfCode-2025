#include <iostream>
using namespace std;

int clearBit(int n, int i) {
    int mask = ~(1 << i);  
    return n & mask;       
}

int main() {
    cout << clearBit(7, 1) << endl;   
    cout << clearBit(10, 3) << endl; 
    return 0;
}
