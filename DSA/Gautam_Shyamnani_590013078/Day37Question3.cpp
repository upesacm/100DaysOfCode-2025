#include <iostream>
#include <stack>
using namespace std;


void deleteMiddle(stack<int>& s, int currentIndex, int middleIndex) {
    
    if (currentIndex == middleIndex) {
        s.pop(); 
        return;
    }

    
    int top = s.top();
    s.pop();

    deleteMiddle(s, currentIndex + 1, middleIndex);

   
    s.push(top);
}

void removeMiddle(stack<int>& s) {
    int size = s.size();
    if (size == 0) return;

    int middleIndex = size / 2; 
    deleteMiddle(s, 0, middleIndex);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Original stack: ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    removeMiddle(s);

    cout << "After deleting middle element: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
