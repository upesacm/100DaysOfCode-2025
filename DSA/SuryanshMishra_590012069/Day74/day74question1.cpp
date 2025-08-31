#include <vector>
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
void nodesAtDistanceKHelper(TreeNode* node, int k, vector<int>& out) {
    if (node == nullptr) return;
    if (k == 0) {
        out.push_back(node->val);
        return;
    }
    nodesAtDistanceKHelper(node->left, k - 1, out);
    nodesAtDistanceKHelper(node->right, k - 1, out);
}
vector<int> nodesAtDistanceK(TreeNode* root, int K) {
    vector<int> result;
    nodesAtDistanceKHelper(root, K, result);
    return result;
}