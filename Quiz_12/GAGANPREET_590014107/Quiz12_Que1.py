# Identify the specific flaw in the validation logic
# -- Flawed Logic in is_valid_bst
#    -This means:
#    -It verifies that the left child is less than the current node.
#    -It verifies that the right child is greater than the current node.

# Why this causes incorrect behavior:
# --Node 6 is in the right subtree of 10, but 6 < 10, which violates the BST property.
#   The current code only checks that 6 < 15, which passes.
#   It fails to check that 6 > 10, which is required for all nodes in the right subtree of 10.
#  -So it incorrectly returns True.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root, min_val=float('-inf'), max_val=float('inf')):
    if not root:
        return True

    if not (min_val < root.val < max_val):
        return False

    return (is_valid_bst(root.left, min_val, root.val) and
            is_valid_bst(root.right, root.val, max_val))
            # Test Case 1: Invalid BST (6 < 10 but in right subtree of 10)
#     10
#    /  \
#   5    15
#       /  \
#      6   20
root1 = TreeNode(10)
root1.left = TreeNode(5)
root1.right = TreeNode(15)
root1.right.left = TreeNode(6)
root1.right.right = TreeNode(20)

print("Test Case 1: Should be False")
print("Is valid BST:", is_valid_bst(root1))  

# Test Case 2: Invalid BST (3 < 5 but in right subtree of 5)
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

print("\nTest Case 2: Should be False")
print("Is valid BST:", is_valid_bst(root2))  

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

print("\nTest Case 3: Should be True")
print("Is valid BST:", is_valid_bst(root3))  
#
Test Case 4: Single Node
root4 = TreeNode(42)

print("\nTest Case 4: Should be True")
print("Is valid BST:", is_valid_bst(root4))  

# Test Case 5: Empty Tree
print("\nTest Case 5: Should be True")
print("Is valid BST:", is_valid_bst(None))  

