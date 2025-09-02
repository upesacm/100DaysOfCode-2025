#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert into BST
Node* insertBST(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->val) 
        root->left = insertBST(root->left, key);
    else if (key > root->val) 
        root->right = insertBST(root->right, key);
    return root;
}

// Inorder traversal (sorted output)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);

    int key = 4;
    root = insertBST(root, key);

    cout << "Inorder after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}
