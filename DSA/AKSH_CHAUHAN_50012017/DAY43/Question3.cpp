#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isPalindrome(queue<char> q) {
    stack<char> s;
    int size = q.size();

    // Push all elements into stack to reverse
    queue<char> temp = q;
    while (!temp.empty()) {
        s.push(temp.front());
        temp.pop();
    }

    // Compare front of queue and top of stack
    while (!q.empty()) {
        if (q.front() != s.top())
            return false;
        q.pop();
        s.pop();
    }

    return true;
}

int main() {
    queue<char> q;
    q.push('r'); q.push('a'); q.push('c'); q.push('e');
    q.push('c'); q.push('a'); q.push('r');

    if (isPalindrome(q))
        cout << "Yes, it's a palindrome." << endl;
    else
        cout << "No, it's not a palindrome." << endl;

    return 0;
}
