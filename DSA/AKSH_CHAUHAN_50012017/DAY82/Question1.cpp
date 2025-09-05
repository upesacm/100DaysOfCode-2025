#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* sortedArrayToBST(vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node* root = sortedArrayToBST(arr, 0, arr.size() - 1);

    cout << "Preorder of Balanced BST: ";
    preorder(root);
    cout << endl;

    return 0;
}
