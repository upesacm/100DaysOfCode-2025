#include <iostream>
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

// Recursive function to print nodes at distance k
void printKDistance(Node* root, int k) {
    if (root == nullptr) return;

    if (k == 0) {
        cout << root->data << " ";
        return;
    }

    printKDistance(root->left, k - 1);
    printKDistance(root->right, k - 1);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2;
    cout << "Nodes at distance " << k << ": ";
    printKDistance(root, k);
    cout << endl;

    return 0;
}
