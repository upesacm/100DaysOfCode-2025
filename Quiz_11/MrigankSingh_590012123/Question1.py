class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def tree_height(root):
    if root is None:
        return 0

    left_height = tree_height(root.left)
    right_height = tree_height(root.right)

    return max(left_height, right_height)
    # BUG: This line doesn't add 1 for the current node
    # The height should be 1 + max(left_height, right_height)
    # Without adding 1, we're not counting the current level


# Test case that reveals the bug:
#     1
#    /
#   2
#  /
# 3
root = TreeNode(1)
root.left = TreeNode(2)
root.left.left = TreeNode(3)

result = tree_height(root)
print(f"Height of tree: {result}")  # Returns 2 instead of 3

# Another test case:
#   1
#  / \
# 2   3
single_node = TreeNode(1)
single_result = tree_height(single_node)
print(f"Height of single node: {single_result}")  # Returns 0 instead of 1


# CORRECTED VERSION:
def tree_height_corrected(root):
    if root is None:
        return 0
    
    left_height = tree_height_corrected(root.left)
    right_height = tree_height_corrected(root.right)
    
    # Add 1 for the current node's level
    return 1 + max(left_height, right_height)


# Test the corrected version
corrected_result = tree_height_corrected(root)
print(f"Corrected height of tree: {corrected_result}")  # Now returns 3

single_corrected = tree_height_corrected(single_node)
print(f"Corrected height of single node: {single_corrected}")  # Now returns 1
