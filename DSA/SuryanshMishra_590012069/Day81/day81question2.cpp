#include <cstddef>
#include <vector>
#include <functional>
using namespace std;

// Tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Convert BST to sorted singly-linked list (new list nodes) using inorder traversal.
ListNode* bstToSortedList(TreeNode* root) {
    if (!root) return nullptr;
    vector<int> vals;
    // inorder traversal collecting values
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        vals.push_back(node->val);
        inorder(node->right);
    };
    inorder(root);
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int v : vals) {
        ListNode* n = new ListNode(v);
        if (!head) head = tail = n;
        else { tail->next = n; tail = n; }
    }
    return head;
}

// Convert BST to right-skewed tree in-place (uses tree nodes as list nodes). Returns new root (leftmost node).
TreeNode* bstToRightSkewed(TreeNode* root) {
    TreeNode* prev = nullptr;
    TreeNode* head = nullptr;
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (!prev) head = node;
        else { prev->right = node; }
        node->left = nullptr;
        prev = node;
        inorder(node->right);
    };
    inorder(root);
    if (prev) prev->right = nullptr;
    return head;
}
