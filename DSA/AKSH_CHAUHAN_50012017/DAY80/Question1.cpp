#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Find LCA in BST
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (!root) return nullptr;

    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root; // split point (ancestor)
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    Node* p = root->left;       // Node 2
    Node* q = root->right;      // Node 8

    Node* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is " << lca->val << endl;

    return 0;
}
