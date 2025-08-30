class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def print_root_to_leaf_paths(root):
    def dfs(node, path):
        if not node:
            return
        path.append(str(node.val))
        if not node.left and not node.right:
            print("->".join(path))
        else:
            dfs(node.left, path)
            dfs(node.right, path)
        path.pop()
    dfs(root, [])

# Example usage:
if __name__ == "__main__":
    # Tree:   1
    #        / \
    #       2   3
    #        \
    #         5
    root = TreeNode(1, TreeNode(2, None, TreeNode(5)), TreeNode(3))
    print_root_to_leaf_paths(root)
    # Output:
    # 1->2->5
    # 1-