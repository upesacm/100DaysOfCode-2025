#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to count nodes at a given level
int countNodesAtLevel(Node* root, int level) {
    if (root == nullptr) return 0;
    if (level == 0) return 1;
    return countNodesAtLevel(root->left, level - 1) +
           countNodesAtLevel(root->right, level - 1);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    int level = 1; // counting from root = level 0
    cout << "Nodes at level " << level << ": " << countNodesAtLevel(root, level) << endl;

    return 0;
}
