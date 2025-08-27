class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def tree_height(root):
    if not root:
        return 0
    return 1 + max(tree_height(root.left), tree_height(root.right))

# Example usage:
if __name__ == "__main__":
    # Tree: 1 / 2 / 3
    root1 = TreeNode(1, TreeNode(2, TreeNode(3)))
    print(tree_height(root1))  # Output: 3
    # Tree: 1 / \ 2 3
    root2 = TreeNode(1, TreeNode(2), TreeNode(3))
    print(tree_height(root2))  #