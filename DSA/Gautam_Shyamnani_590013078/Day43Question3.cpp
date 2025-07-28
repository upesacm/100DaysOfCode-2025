#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isPalindrome(queue<char> q) {
    stack<char> s;
    int size = q.size();

    
    for (int i = 0; i < size; ++i) {
        char ch = q.front();
        s.push(ch);
        q.push(ch);     
        q.pop();
    }

    
    for (int i = 0; i < size; ++i) {
        char chQueue = q.front(); q.pop();
        char chStack = s.top(); s.pop();

        if (chQueue != chStack)
            return false;
    }

    return true;
}

int main() {
    queue<char> q1;
    string word = "racecar";  
    for (char ch : word) {
        q1.push(ch);
    }

    if (isPalindrome(q1))
        cout << "Yes, it's a palindrome!" << endl;
    else
        cout << "Nope, not a palindrome." << endl;

    return 0;
}
