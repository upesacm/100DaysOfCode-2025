class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sum_of_nodes(root):
    if not root:
        return 0
    return root.val + sum_of_nodes(root.left) + sum_of_nodes(root.right)

# Example usage:
if __name__ == "__main__":
    # Tree: 1 / \ 2 3
    root1 = TreeNode(1, TreeNode(2), TreeNode(3))
    print(sum_of_nodes(root1))  # Output: 6

    # Tree: 10 / 5
    root2 = TreeNode(10, TreeNode(5))
    print(sum_of_nodes(root2))  # Output: 15