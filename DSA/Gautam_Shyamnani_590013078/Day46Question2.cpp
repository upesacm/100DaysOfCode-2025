#include <iostream>
#include <queue>

void countEvenOdd(std::queue<int> q) {
    int evenCount = 0, oddCount = 0;

    // Traverse the queue without modifying the original
    while (!q.empty()) {
        int current = q.front();  // Peek at the front
        if (current % 2 == 0)
            ++evenCount;
        else
            ++oddCount;
        q.pop(); // Move to next person in line
    }

    std::cout << "Even: " << evenCount << ", Odd: " << oddCount << std::endl;
}

int main() {
    std::queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);

    countEvenOdd(myQueue);

    return 0;
}
