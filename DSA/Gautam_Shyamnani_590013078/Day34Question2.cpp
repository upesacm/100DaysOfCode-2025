#include <iostream>
using namespace std;

int subtractOne(int n) {
    int m = 1;

    while (!(n & m)) {
        n = n ^ m;      
        m = m << 1;     
    }

    n = n ^ m;          
    return n;
}

int main() {
    int n = 8; 
    cout << "Result: " << subtractOne(n) << endl;
    return 0;
}
