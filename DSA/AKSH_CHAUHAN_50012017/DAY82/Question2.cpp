#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int checkHeight(Node* root) {
    if (!root) return 0;

    int leftH = checkHeight(root->left);
    if (leftH == -1) return -1;

    int rightH = checkHeight(root->right);
    if (rightH == -1) return -1;

    if (abs(leftH - rightH) > 1) return -1;

    return max(leftH, rightH) + 1;
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(3);

    cout << "Is Balanced? " << (isBalanced(root) ? "Yes" : "No") << endl;

    return 0;
}
