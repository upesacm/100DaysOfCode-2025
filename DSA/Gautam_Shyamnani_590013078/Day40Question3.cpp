#include <iostream>
#include <vector>
using namespace std;

class MaxStack {
private:
    vector<int> stack;
    vector<int> max_stack;

public:
    void push(int x) {
        stack.push_back(x);
        if (max_stack.empty() || x >= max_stack.back()) {
            max_stack.push_back(x);
        }
    }

    void pop() {
        if (!stack.empty()) {
            int val = stack.back();
            stack.pop_back();
            if (val == max_stack.back()) {
                max_stack.pop_back();
            }
        }
    }

    int getMax() {
        if (!max_stack.empty()) {
            return max_stack.back();
        }
        return -1; // or throw an exception for empty stack
    }
};

int main() {
    MaxStack s;
    s.push(3);
    s.push(5);
    s.push(2);
    cout << s.getMax() << endl; // Output: 5

    s.pop();
    cout << s.getMax() << endl; // Output: 5

    return 0;
}
