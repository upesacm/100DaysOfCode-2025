#include <iostream>
#include <queue>
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

// Function to print left view
void leftView(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        // Traverse current level
        for (int i = 1; i <= n; i++) {
            Node* node = q.front();
            q.pop();

            // First node of this level
            if (i == 1) {
                cout << node->data << " ";
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    cout << "Left view: ";
    leftView(root);
    cout << endl;

    return 0;
}
