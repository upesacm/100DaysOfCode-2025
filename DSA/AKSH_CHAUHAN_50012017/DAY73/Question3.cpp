#include <iostream>
#include <algorithm> // for max
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to find maximum value in tree
int findMax(Node* root) {
    if (root == nullptr) return INT_MIN;
    return max(root->val, max(findMax(root->left), findMax(root->right)));
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(5);

    cout << "Maximum value in tree: " << findMax(root) << endl;

    return 0;
}
