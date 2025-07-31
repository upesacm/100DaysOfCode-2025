#include <iostream>
#include <queue>

std::queue<int> mergeQueues(std::queue<int> q1, std::queue<int> q2) {
    // Append all elements from q2 to q1
    while (!q2.empty()) {
        q1.push(q2.front());  // Add front of q2 to the end of q1
        q2.pop();             // Remove the element we just added
    }

    return q1;
}

int main() {
    std::queue<int> Q1;
    std::queue<int> Q2;

    // Filling Q1 and Q2
    Q1.push(1);
    Q1.push(2);
    Q2.push(3);
    Q2.push(4);

    std::queue<int> merged = mergeQueues(Q1, Q2);

    // Displaying the merged queue
    std::cout << "Merged Queue: ";
    while (!merged.empty()) {
        std::cout << merged.front() << " ";
        merged.pop();
    }

    return 0;
}
