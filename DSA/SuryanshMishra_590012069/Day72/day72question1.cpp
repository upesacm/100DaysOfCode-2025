#include <cstddef>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirrorTree(root->left);
    mirrorTree(root->right);

    return root;
}