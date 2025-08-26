class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def count_nodes(root):
    if not root:
        return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)

# Example usage:
if __name__ == "__main__":
    # Tree: 1 / \ 2 3
    root1 = TreeNode(1, TreeNode(2), TreeNode(3))
    print(count_nodes(root1))  # Output: 3

    # Tree: 5 \ 6
    root2 = TreeNode(5, None, TreeNode(6))
    print(count_nodes(root2))  # Output: