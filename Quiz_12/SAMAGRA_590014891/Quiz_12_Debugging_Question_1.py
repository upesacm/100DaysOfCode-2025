class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root):
    def helper(node, low=float("-inf"), high=float("inf")):
        if not node:
            return True
        if not (low < node.val < high):
            return False
        return helper(node.left, low, node.val) and helper(node.right, node.val, high)
    return helper(root)

# The bug and fix

# The original code was only checking the immediate left and right child of a node.
# That "works" for some cases, but fails when the violation is deeper in the tree.
# Example: in the first test, 6 is in the right subtree of 10, but still less than 10.
# The old code missed that because it only looked one level down.

# The reason this breaks BST validation is that the BST property isn’t just
# parent <-> child, it applies to the whole subtree:
#   - all nodes in the left subtree must be < root
#   - all nodes in the right subtree must be > root
# Without keeping track of valid ranges, you can’t catch these deeper violations.

# The fix I used: instead of only comparing parent and child, I pass down a valid
# range (low, high) for each recursive call. That way every node is checked against
# the limits set by ALL of its ancestors, not just its parent.

# -------------------------------
# Test cases
# -------------------------------

# Test case 1:
#     10
#    /  \
#   5    15
#       /  \
#      6   20
# 6 is on the right of 10 but smaller than 10, so this is NOT a valid BST.
root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(15)
root.right.left = TreeNode(6)
root.right.right = TreeNode(20)

result = is_valid_bst(root)
print(f"Is valid BST: {result}")  # Expected: False

# Test case 2:
#     5
#    / \
#   1   4
#      / \
#     3   6
# 4 is on the right of 5 but smaller than 5, so again NOT a valid BST.
root2 = TreeNode(5)
root2.left = TreeNode(1)
root2.right = TreeNode(4)
root2.right.left = TreeNode(3)
root2.right.right = TreeNode(6)

result2 = is_valid_bst(root2)
print(f"Is valid BST: {result2}")  # Expected: False

# Test case 3 (valid one just to confirm fix works):
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

result3 = is_valid_bst(root3)
print(f"Is valid BST: {result3}")  
