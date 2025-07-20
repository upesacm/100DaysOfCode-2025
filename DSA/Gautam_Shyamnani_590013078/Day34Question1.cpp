#include <iostream>
using namespace std;

int addOne(int n) {
    int m = 1;

    
    while (n & m) {
        n = n ^ m;      
        m = m << 1;     
    }

    n = n ^ m;         

    return n;
}

int main() {
    int n = 7; 
    cout << "Result: " << addOne(n) << endl;
    return 0;
}
