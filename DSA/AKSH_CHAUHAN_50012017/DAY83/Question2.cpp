#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    std::string serialize(TreeNode* root) {
        std::stringstream ss;
        serializeHelper(root, ss);
        std::string result = ss.str();
        if (!result.empty()) result.pop_back();
        return result;
    }

    TreeNode* deserialize(std::string data) {
        if (data.empty()) return nullptr;
        std::queue<int> q;
        std::stringstream ss(data);
        std::string item;
        while (getline(ss, item, ',')) {
            q.push(std::stoi(item));
        }
        return deserializeHelper(q, INT_MIN, INT_MAX);
    }

private:
    void serializeHelper(TreeNode* root, std::stringstream& ss) {
        if (!root) return;
        ss << root->val << ",";
        serializeHelper(root->left, ss);
        serializeHelper(root->right, ss);
    }

    TreeNode* deserializeHelper(std::queue<int>& q, int min_bound, int max_bound) {
        if (q.empty() || q.front() < min_bound || q.front() > max_bound) {
            return nullptr;
        }
        
        int val = q.front();
        q.pop();
        TreeNode* root = new TreeNode(val);
        
        root->left = deserializeHelper(q, min_bound, val);
        root->right = deserializeHelper(q, val, max_bound);
        
        return root;
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    Codec codec;
    std::string serialized = codec.serialize(root);
    std::cout << "Input Tree Inorder: 1 2 3" << std::endl;
    std::cout << "Serialized: \"" << serialized << "\"" << std::endl;
    
    TreeNode* deserialized_root = codec.deserialize(serialized);
    std::cout << "Deserialized Inorder: ";
    printInorder(deserialized_root);
    std::cout << std::endl;
    
    return 0;
}