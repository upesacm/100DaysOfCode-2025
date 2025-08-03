#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

// Function to check if all elements in the queue are unique
bool areElementsUnique(queue<int> q) {
    unordered_set<int> seen;

    // Traverse the queue
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // If we've seen this element before, it's a duplicate
        if (seen.count(current)) {
            return false;
        }

        // Otherwise, mark it as seen
        seen.insert(current);
    }

    // If we made it through the whole queue, all elements are unique
    return true;
}

int main() {
    // Example input
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // Check for uniqueness
    bool result = areElementsUnique(q);

    // Display result
    cout << "Are all elements unique? " << (result ? "True" : "False") << endl;

    return 0;
}
