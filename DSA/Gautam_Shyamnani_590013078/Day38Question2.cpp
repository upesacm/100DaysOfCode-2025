#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack; 

public:
    void push(int x) {
        mainStack.push(x);
        
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top() {
        return mainStack.empty() ? -1 : mainStack.top();
    }

    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};

int main() {
    MinStack st;
    st.push(8);
    st.push(2);
    st.push(6);
    st.pop();      
    cout << st.getMin() << endl; 
    return 0;
}
