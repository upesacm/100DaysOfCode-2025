#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to sum all nodes
int sumNodes(Node* root) {
    if (root == nullptr) return 0;
    return root->val + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "Sum of all nodes: " << sumNodes(root) << endl;

    return 0;
}
