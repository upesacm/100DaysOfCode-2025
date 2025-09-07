#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Range sum with pruning
int rangeSumBST(Node* root, int L, int R) {
    if (!root) return 0;

    if (root->val < L) return rangeSumBST(root->right, L, R);
    if (root->val > R) return rangeSumBST(root->left, L, R);

    return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    int L = 7, R = 15;
    cout << "Range Sum [" << L << "," << R << "] = " << rangeSumBST(root, L, R) << endl;

    return 0;
}
