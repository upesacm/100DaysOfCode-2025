#include <iostream>
#include <queue>
using namespace std;


void displayQueue(queue<int> q) {
    cout << "Queue contents (front to rear): ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop(); 
    }
    cout << endl;
}

int main() {
    queue<int> myQueue;

   
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    
    displayQueue(myQueue);

    cout << "Size of original queue: " << myQueue.size() << endl;

    return 0;
}
