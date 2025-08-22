#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Function to count occurrences of each element in the queue
unordered_map<int, int> countFrequencies(queue<int> q) {
    unordered_map<int, int> frequencyMap;

    // Traverse the queue
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Increment the count for this element
        frequencyMap[current]++;
    }

    return frequencyMap;
}

int main() {
    // Example input
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(2);
    q.push(3);
    q.push(1);
    q.push(1);

    // Count frequencies
    unordered_map<int, int> frequencies = countFrequencies(q);

    // Display the frequency distribution
    cout << "Frequency Distribution:\n";
    for (auto pair : frequencies) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
