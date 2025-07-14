#include <iostream>
using namespace std;

int main() {
    int n, i;
    cout << "Enter a number (n): ";
    cin >> n;
    cout << "Enter the bit position to check (i): ";
    cin >> i;

    
    int mask = 1 << i;     
    int result = (n & mask) ? 1 : 0;  

    cout << "The bit at position " << i << " is: " << result << endl;

    return 0;
}
