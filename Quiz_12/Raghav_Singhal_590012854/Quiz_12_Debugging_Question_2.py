class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def range_sum_bst(root, L, R):
    # Base case: if the node is None, return 0
    if not root:
        return 0

    # If the current node value is less than L, ignore the left subtree
    if root.val < L:
        return range_sum_bst(root.right, L, R)

    # If the current node value is greater than R, ignore the right subtree
    if root.val > R:
        return range_sum_bst(root.left, L, R)

    # If the current node is within range, add it and explore both subtrees
    return root.val + range_sum_bst(root.left, L, R) + range_sum_bst(root.right, L, R)


# ------------------ TESTING ------------------

# Constructing the BST
root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(15)
root.left.left = TreeNode(3)
root.left.right = TreeNode(7)
root.right.left = TreeNode(13)
root.right.right = TreeNode(18)
root.left.left.left = TreeNode(1)
root.left.right.left = TreeNode(6)
root.right.right.right = TreeNode(20)

# Test case: sum of values in range [7, 15]
result = range_sum_bst(root, 7, 15)
print(f"Range sum [7,15]: {result}")  # Expected Output: 45
