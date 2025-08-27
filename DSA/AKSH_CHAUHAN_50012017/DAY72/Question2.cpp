#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to check identical trees
bool isIdentical(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;

    return (root1->val == root2->val) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if (isIdentical(root1, root2))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
