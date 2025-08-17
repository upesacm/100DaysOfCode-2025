#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>

class MedianFinder {
private:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    void insert(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }

        if (num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double getMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

void findMedianStream(const std::vector<int>& arr) {
    MedianFinder finder;
    for (size_t i = 0; i < arr.size(); i++) {
        finder.insert(arr[i]);
        double median = finder.getMedian();
        if (median == static_cast<int>(median)) {
            std::cout << static_cast<int>(median);
        } else {
            std::cout << median;
        }
        if (i < arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::string line;
    std::cout << "Enter the stream of integers separated by spaces: ";
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> arr;
    int num;
    while (iss >> num) {
        arr.push_back(num);
    }

    if (arr.empty()) {
        std::cout << "No input provided." << std::endl;
        return 0;
    }

    std::cout << "Output: ";
    findMedianStream(arr);

    return 0;
}
