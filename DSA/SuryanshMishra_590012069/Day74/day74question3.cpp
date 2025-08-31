#include <vector>
#include <string>
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
void dfsPath(TreeNode* node, string& cur, vector<string>& out) {
    if (!node) return;
    int old = cur.size();
    if (!cur.empty()) cur += "->";
    cur += to_string(node->val);
    if (node->left == nullptr && node->right == nullptr) {
        out.push_back(cur);
    } else {
        dfsPath(node->left, cur, out);
        dfsPath(node->right, cur, out);
    }
    cur.resize(old);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    string cur;
    dfsPath(root, cur, res);
    return res;
}