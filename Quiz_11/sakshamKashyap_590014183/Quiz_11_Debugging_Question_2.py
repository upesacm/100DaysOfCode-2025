# 1. What's wrong with the sum tree conversion logic?
# The code correctly updates each node's value to the sum of its left and right subtrees,
# but it does not explicitly set leaf nodes to 0. Leaf nodes retain their original value,
# which violates the sum tree definition.

# 2. Why leaf nodes don't become 0 as expected?
# The function sets root.val = left_sum + right_sum for all nodes, but for leaf nodes,
# both left_sum and right_sum are 0, so root.val becomes 0. This is correct.
# However, if a leaf node is not handled explicitly, some implementations may not set it to 0.

# 3. Correct implementation for proper sum tree conversion:
# Explicitly set leaf nodes to 0 after recursive calls, ensuring all leaves are converted.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def convert_to_sum_tree(root):
    """
    Converts a binary tree to a sum tree.
    Each node's value becomes the sum of all nodes in its left and right subtrees.
    Leaf nodes become 0.
    Returns the sum of the subtree rooted at root (including original root value).
    """
    if not root:
        return 0

    old_val = root.val
    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)

    root.val = left_sum + right_sum
    return old_val + left_sum + right_sum

def print_inorder(root):
    if root:
        print_inorder(root.left)
        print(root.val, end=" ")
        print_inorder(root.right)

# Test case:
#     1
#    / \
#   2   3
#  / \
# 4   5
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

print("Original tree (inorder):")
print_inorder(root)
print()

convert_to_sum_tree(root)
print("After conversion (inorder):")
print_inorder(root)
print()