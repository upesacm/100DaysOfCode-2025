#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to print ancestors
bool printAncestors(Node* root, int target) {
    if (root == nullptr) return false;

    if (root->val == target) return true;

    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        cout << root->val << " ";
        return true;
    }

    return false;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    int target = 4;
    cout << "Ancestors of " << target << ": ";
    printAncestors(root, target);
    cout << endl;

    return 0;
}
