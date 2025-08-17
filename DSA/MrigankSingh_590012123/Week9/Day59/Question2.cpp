#include <iostream>
#include <queue>
#include <vector>

class MaxHeap {
private:
    std::priority_queue<int> pq;

public:
    void insert(int value) {
        pq.push(value);
    }

    int extractMax() {
        if (pq.empty()) {
            std::cerr << "Error: Heap is empty. Cannot extract maximum.\n";
            return -1; 
        }
        int max = pq.top();
        pq.pop();
        return max;
    }

    bool isEmpty() {
        return pq.empty();
    }

    void peekMax() {
        if (pq.empty()) {
            std::cerr << "Error: Heap is empty. No maximum element.\n";
        } else {
            std::cout << "Current maximum element: " << pq.top() << std::endl;
        }
    }

    void printHeap() {
        if (pq.empty()) {
            std::cout << "Heap is empty.\n";
            return;
        }
        std::priority_queue<int> temp = pq;
        std::cout << "Heap elements: ";
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap heap;
    int choice, value, n;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert elements\n";
        std::cout << "2. Extract maximum element\n";
        std::cout << "3. Peek maximum element\n";
        std::cout << "4. Print all elements\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the number of elements to insert: ";
                std::cin >> n;
                std::cout << "Enter the elements: ";
                for (int i = 0; i < n; i++) {
                    std::cin >> value;
                    heap.insert(value);
                }
                break;
            case 2:
                value = heap.extractMax();
                if (value != -1) {
                    std::cout << "Extracted maximum element: " << value << std::endl;
                }
                break;
            case 3:
                heap.peekMax();
                break;
            case 4:
                heap.printHeap();
                break;
            case 5:
                return 0;
            default:
                std::cerr << "Invalid choice. Please try again.\n";
        }
    }
}
