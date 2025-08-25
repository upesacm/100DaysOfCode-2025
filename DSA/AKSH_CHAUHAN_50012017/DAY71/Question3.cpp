#include <iostream>
#include <algorithm> // for max
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to find height
int height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int main() {
    // Example 1:
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);

    cout << "Height: " << height(root) << endl;

    return 0;
}
