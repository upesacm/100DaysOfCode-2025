#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void convertBST(Node* root, int& sum) {
    if (!root) return;

    convertBST(root->right, sum);

    sum += root->val;
    root->val = sum;

    convertBST(root->left, sum);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(13);

    int sum = 0;
    convertBST(root, sum);

    cout << "Inorder of Greater Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
