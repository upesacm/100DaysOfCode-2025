#include <string>
#include <vector>
#include <sstream>
#include <cstddef>
#include <limits>
#include <functional>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Serialize BST using preorder traversal (comma-separated values, no null markers).
string serialize(TreeNode* root) {
    if (!root) return string();
    string out;
    // iterative or recursive preorder
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) return;
        if (!out.empty()) out.push_back(',');
        out += to_string(node->val);
        dfs(node->left);
        dfs(node->right);
    };
    dfs(root);
    return out;
}

// Helper to rebuild BST from preorder sequence using bounds.
TreeNode* buildFromPreorder(const vector<int>& pre, int &idx, long long lower, long long upper) {
    if (idx >= (int)pre.size()) return nullptr;
    int val = pre[idx];
    if (val <= lower || val >= upper) return nullptr;
    // create node
    TreeNode* node = new TreeNode(val);
    idx++;
    node->left = buildFromPreorder(pre, idx, lower, val);
    node->right = buildFromPreorder(pre, idx, val, upper);
    return node;
}

// Deserialize string (preorder) into BST using range-based reconstruction.
TreeNode* deserialize(const string& data) {
    if (data.empty()) return nullptr;
    vector<int> pre;
    string token;
    stringstream ss(data);
    while (getline(ss, token, ',')) {
        if (!token.empty()) pre.push_back(stoi(token));
    }
    int idx = 0;
    return buildFromPreorder(pre, idx, numeric_limits<long long>::lowest(), numeric_limits<long long>::max());
}
