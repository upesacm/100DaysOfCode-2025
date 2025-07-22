#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& input) {
    stack<int> tempStack;

    
    while (!input.empty()) {
        int current = input.top();
        input.pop();

       
        while (!tempStack.empty() && tempStack.top() > current) {
            input.push(tempStack.top());
            tempStack.pop();
        }

        
        tempStack.push(current);
    }

   
    while (!tempStack.empty()) {
        input.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> myStack;
    myStack.push(3);
    myStack.push(1);
    myStack.push(4);
    myStack.push(2);

    cout << "Before sorting: ";
    stack<int> temp = myStack;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(myStack);

    cout << "After sorting: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
