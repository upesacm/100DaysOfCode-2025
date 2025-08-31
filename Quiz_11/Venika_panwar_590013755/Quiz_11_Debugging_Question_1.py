# 1. Buggy line in the code:
#     return max(left_height, right_height)
#
# 2. Why this causes incorrect behavior:
# The height of a binary tree is defined as the number of nodes along the
# longest path from the root to a leaf. The buggy line only compares the
# heights of the left and right subtrees but fails to count the current node.
# This results in the height being undercounted by 1 for every level.
#
# Example:
#     1
#    /
#   2
#  /
# 3
# Incorrect output: 2
# Correct output: 3
#
# 3. Corrected Code

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def tree_height(root):
    """
    Calculate the height of a binary tree.
    
    Height definition:
    - Empty tree has height 0.
    - A single node has height 1.
    - Otherwise, 1 + max(height of left subtree, height of right subtree).
    """
    if root is None:
        return 0
    
    left_height = tree_height(root.left)
    right_height = tree_height(root.right)
    
    # FIX: add +1 to include the current node
    return 1 + max(left_height, right_height)


# ---------------- TEST CASES ----------------

# Test Case 1: Skewed left tree
#     1
#    /
#   2
#  /
# 3
root = TreeNode(1)
root.left = TreeNode(2)
root.left.left = TreeNode(3)
print("Height of skewed left tree:", tree_height(root))  # Expected: 3

# Test Case 2: Perfect binary tree
#       1
#      / \
#     2   3
#    / \
#   4   5
perfect_root = TreeNode(1)
perfect_root.left = TreeNode(2)
perfect_root.right = TreeNode(3)
perfect_root.left.left = TreeNode(4)
perfect_root.left.right = TreeNode(5)
print("Height of perfect binary tree:", tree_height(perfect_root))  # Expected: 3

# Test Case 3: Single node
single_node = TreeNode(1)
print("Height of single node tree:", tree_height(single_node))  # Expected: 1

# Test Case 4: Empty tree
print("Height of empty tree:", tree_height(None))  # Expected: 0

# Test Case 5: Right-skewed tree
# 1
#  \
#   2
#    \
#     3
right_root = TreeNode(1)
right_root.right = TreeNode(2)
right_root.right.right = TreeNode(3)
print("Height of skewed right tree:", tree_height(right_root))  # Expected: 3
