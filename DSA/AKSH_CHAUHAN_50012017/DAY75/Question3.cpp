#include <iostream>
#include <algorithm>
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

int diameterUtil(Node* root, int& diameter) {
    if (root == nullptr) return 0;

    int leftHeight = diameterUtil(root->left, diameter);
    int rightHeight = diameterUtil(root->right, diameter);

    // Update diameter: longest path through this node
    diameter = max(diameter, leftHeight + rightHeight);

    // Height of this node
    return max(leftHeight, rightHeight) + 1;
}

int diameter(Node* root) {
    int dia = 0;
    diameterUtil(root, dia);
    return dia;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Diameter of tree: " << diameter(root) << endl;

    return 0;
}
