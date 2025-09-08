#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Print nodes in range with pruning
void printInRange(Node* root, int L, int R) {
    if (!root) return;

    if (root->val > L) 
        printInRange(root->left, L, R);

    if (root->val >= L && root->val <= R)
        cout << root->val << " ";

    if (root->val < R)
        printInRange(root->right, L, R);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    int L = 7, R = 15;
    cout << "Nodes in range [" << L << "," << R << "]: ";
    printInRange(root, L, R);
    cout << endl;

    return 0;
}
