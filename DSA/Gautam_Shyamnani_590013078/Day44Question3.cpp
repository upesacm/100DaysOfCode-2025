#include <iostream>
#include <queue>
using namespace std;


bool isQueueEmpty(queue<int> q) {
    return q.empty();  
}

int main() {
    queue<int> myQueue;

    
    cout << "Is queue empty? " << (isQueueEmpty(myQueue) ? "True" : "False") << endl;

    
    myQueue.push(1);
    myQueue.push(2);

    cout << "Is queue empty after adding elements? " << (isQueueEmpty(myQueue) ? "True" : "False") << endl;

    return 0;
}
