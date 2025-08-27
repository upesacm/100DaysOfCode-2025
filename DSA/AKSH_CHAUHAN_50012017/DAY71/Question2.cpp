#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Count leaf nodes recursively
int countLeaves(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    // Example 1:
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "Leaf count: " << countLeaves(root) << endl;

    return 0;
}
