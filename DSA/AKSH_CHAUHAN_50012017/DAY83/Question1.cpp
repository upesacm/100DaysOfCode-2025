#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> verticalOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) return result;

        std::map<int, std::vector<int>> hdMap;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            std::pair<TreeNode*, int> current = q.front();
            q.pop();
            
            TreeNode* node = current.first;
            int hd = current.second;

            hdMap[hd].push_back(node->val);

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (auto const& pair : hdMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};

void printVectorOfVectors(const std::vector<std::vector<int>>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < vec[i].size(); ++j) {
            std::cout << vec[i][j] << (j == vec[i].size() - 1 ? "" : ",");
        }
        std::cout << "]" << (i == vec.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    Solution sol;
    std::vector<std::vector<int>> vertical = sol.verticalOrder(root);
    
    std::cout << "Input Tree: 3 -> (9, 20), 20 -> (15, 7)" << std::endl;
    std::cout << "Output: ";
    printVectorOfVectors(vertical);
    return 0;
}