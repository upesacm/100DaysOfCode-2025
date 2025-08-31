#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to convert to sum tree
int toSumTree(Node* root) {
    if (root == nullptr) return 0;

    int oldVal = root->val;

    // Recursively convert left and right subtrees
    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);

    // Update current node value
    root->val = leftSum + rightSum;

    // Return sum of values under this subtree (including oldVal)
    return root->val + oldVal;
}

// Inorder traversal to check transformation
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    cout << "Original tree (inorder): ";
    inorder(root);
    cout << endl;

    toSumTree(root);

    cout << "Sum tree (inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
