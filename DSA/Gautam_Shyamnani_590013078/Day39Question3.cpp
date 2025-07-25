#include <iostream>
using namespace std;

class TwoStacks {
private:
    int* arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;       
        top2 = n;         
    }

    
    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            cout << "Stack Overflow in Stack1\n";
        }
    }

    
    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            cout << "Stack Overflow in Stack2\n";
        }
    }

   
    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack1 Underflow\n";
            return -1;
        }
    }

    
    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            cout << "Stack2 Underflow\n";
            return -1;
        }
    }

    
    void printStacks() {
        cout << "Stack1: ";
        for (int i = 0; i <= top1; ++i)
            cout << arr[i] << " ";
        cout << "\nStack2: ";
        for (int i = size - 1; i >= top2; --i)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~TwoStacks() {
        delete[] arr;
    }
};

int main() {
    TwoStacks ts(10);

    ts.push1(1);
    ts.push1(2);
    ts.push2(9);
    ts.push2(8);

    ts.printStacks();

    ts.push1(3);
    ts.pop2();

    ts.printStacks();

    return 0;
}
