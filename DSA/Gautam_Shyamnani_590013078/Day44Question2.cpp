#include <iostream>
#include <queue>
using namespace std;


int getQueueSize(queue<int> q) {
    return q.size();  
}

int main() {
    queue<int> myQueue;

    
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);

    
    cout << "Number of elements in queue: " << getQueueSize(myQueue) << endl;

    return 0;
}
