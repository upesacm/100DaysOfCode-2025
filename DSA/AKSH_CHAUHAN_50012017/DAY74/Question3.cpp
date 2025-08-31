#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Recursive function to print paths
void printPaths(Node* root, vector<int>& path) {
    if (root == nullptr) return;

    path.push_back(root->data);

    // If leaf node, print the path
    if (root->left == nullptr && root->right == nullptr) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) cout << "->";
        }
        cout << endl;
    } else {
        // Recurse on left and right children
        printPaths(root->left, path);
        printPaths(root->right, path);
    }

    // Backtrack
    path.pop_back();
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    vector<int> path;
    cout << "Root to leaf paths:\n";
    printPaths(root, path);

    return 0;
}
