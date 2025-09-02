#include <iostream>
#include <limits>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive validation function
bool isValidBST(Node* root, long minVal, long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    cout << "Is valid BST? " 
         << (isValidBST(root, numeric_limits<long>::min(), numeric_limits<long>::max()) ? "Yes" : "No") 
         << endl;

    return 0;
}