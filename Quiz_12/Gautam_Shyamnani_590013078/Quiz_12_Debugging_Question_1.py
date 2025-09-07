class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root):
    def helper(node, min_val, max_val):
        if not node:
            return True
        if not (min_val < node.val < max_val):
            return False
        return helper(node.left, min_val, node.val) and helper(node.right, node.val, max_val)

    return helper(root, float('-inf'), float('inf'))

# Test Case 1: Invalid BST
#     10
#    /  \
#   5    15
#       /  \
#      6   20
root1 = TreeNode(10)
root1.left = TreeNode(5)
root1.right = TreeNode(15)
root1.right.left = TreeNode(6)   # Invalid: 6 < 10 but in right subtree
root1.right.right = TreeNode(20)

print(f"Is valid BST (Test 1): {is_valid_bst(root1)}")  # Expected: False

# Test Case 2: Invalid BST
#     5
#    / \
#   1   4
#      / \
#     3   6
root2 = TreeNode(5)
root2.left = TreeNode(1)
root2.right = TreeNode(4)
root2.right.left = TreeNode(3)
root2.right.right = TreeNode(6)

print(f"Is valid BST (Test 2): {is_valid_bst(root2)}")  # Expected: False

# Test Case 3: Valid BST
#     8
#    / \
#   3   10
#      /  \
#     9   14
root3 = TreeNode(8)
root3.left = TreeNode(3)
root3.right = TreeNode(10)
root3.right.left = TreeNode(9)
root3.right.right = TreeNode(14)

print(f"Is valid BST (Test 3): {is_valid_bst(root3)}")  # Expected: True
