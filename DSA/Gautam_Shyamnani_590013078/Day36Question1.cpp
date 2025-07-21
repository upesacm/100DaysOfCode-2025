#include <iostream>
#include <stack>
using namespace std;

string reverseString(string input) {
    stack<char> s;

    for (char ch : input) {
        s.push(ch);
    }

    
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top(); 
        s.pop();             
    }

    return reversed;
}

int main() {
    string str = "hello";
    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reverseString(str) << endl;
    return 0;
}
