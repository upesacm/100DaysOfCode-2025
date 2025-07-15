#include <iostream>
using namespace std;

int main() {
    int n, i;
    cout << "Enter a number (n): ";
    cin >> n;
    cout << "Enter the bit position you want to set (i): ";
    cin >> i;

    
    int mask = 1 << i;

    int newNumber = n | mask;

    cout << "The new number after setting bit " << i << " is: " << newNumber << endl;

    return 0;
}
