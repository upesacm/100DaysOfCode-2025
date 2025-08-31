
# 1. Identify the specific line(s) causing the bug:
# The bug is in the return statement:
#     return max(left_height, right_height)
# This line omits the current node's contribution to the height.
#
# 2. Why this causes incorrect behavior:
# The height of a binary tree is defined as the number of nodes along the longest path from the root to a leaf.
# By not adding 1 for the current node, the function undercounts the height by 1 for every level.
#
# 3. Corrected code:

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def tree_height(root):
    """
    Returns the height of a binary tree.
    Height is defined as the number of nodes along the longest path from root to leaf.
    For an empty tree, height is 0.
    For a single node, height is 1.
    """
    if root is None:
        return 0
    left_height = tree_height(root.left)
    right_height = tree_height(root.right)
    # Add 1 for the current node
    return 1 + max(left_height, right_height)

# Edge case: empty tree
empty_result = tree_height(None)
print(f"Height of empty tree: {empty_result}")  # Output: 0

# Test case 1: left-skewed tree
#     1
#    /
#   2
#  /
# 3
root = TreeNode(1)
root.left = TreeNode(2)
root.left.left = TreeNode(3)
result = tree_height(root)
print(f"Height of left-skewed tree: {result}")  # Output: 3

# Test case 2: single node
single_node = TreeNode(1)
single_result = tree_height(single_node)
print(f"Height of single node: {single_result}")  # Output: 1

# Test case 3: balanced tree
#   1
#  / \
# 2   3
balanced_root = TreeNode(1, TreeNode(2), TreeNode(3))
balanced_result = tree_height(balanced_root)
print(f"Height of balanced tree: {balanced_result}")  # Output: 2

# Test case 4: right-skewed tree
# 1
#  \
#   2
#    \
#     3
right_root = TreeNode(1, None, TreeNode(2, None, TreeNode(3)))
right_result = tree_height(right_root)
print(f"Height of right-skewed tree: {right_result}")  # Output: 3