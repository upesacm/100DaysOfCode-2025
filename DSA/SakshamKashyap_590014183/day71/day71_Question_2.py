class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def count_leaves(root):
    if not root:
        return 0
    if not root.left and not root.right:
        return 1
    return count_leaves(root.left) + count_leaves(root.right)

# Example usage:
if __name__ == "__main__":
    # Tree: 1 / \ 2 3
    root1 = TreeNode(1, TreeNode(2), TreeNode(3))
    print(count_leaves(root1))  # Output: 2
    # Tree: 10 \ 20 / 15
    root2 = TreeNode(10, None, TreeNode(20, TreeNode(15)))
    print(count_leaves(root2))  # Output: 1