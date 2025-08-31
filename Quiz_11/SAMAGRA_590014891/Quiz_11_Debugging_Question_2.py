class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def convert_to_sum_tree(root):
    if not root:
        return 0

    old_val = root.val  # Store the original node value

    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)

    # BUG: This line sets the node value to only left+right sums,
    # but it never handles leaf nodes specially.
    # As a result, leaves end up keeping their original values 
    # because the function just returns old_val + left_sum + right_sum.
    # We want LEAF nodes to become 0, but this logic doesn't do that.
    root.val = left_sum + right_sum

    # Returning this total is fine, but the node's value logic is wrong for leaves
    return old_val + left_sum + right_sum


# Correct approach: A proper sum tree conversion should:
# 1. Recursively calculate the sum of the left and right subtrees.
# 2. Update the current node’s value to (left_sum + right_sum),
#    making leaf nodes automatically become 0 (since both sums will be 0).
# 3. Return old_val + left_sum + right_sum for parent calculations.

def correct_convert_to_sum_tree(root):
    if not root:
        return 0

    old_val = root.val
    left_sum = correct_convert_to_sum_tree(root.left)
    right_sum = correct_convert_to_sum_tree(root.right)

    # Correctly set node's value to the sum of left and right children
    root.val = left_sum + right_sum
    return old_val + left_sum + right_sum


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


def print_inorder(root):
    if root:
        print_inorder(root.left)
        print(root.val, end=" ")
        print_inorder(root.right)


print("Original tree (inorder):")
print_inorder(root)
print()

correct_convert_to_sum_tree(root)
print("After conversion (inorder):")
print_inorder(root)
print()

# Expected output:
# The tree values after conversion should be:
#       14
#      /  \
#     9    0
#    / \
#   0   0
# Leaf nodes (4,5,3) become 0, and parent nodes are sums of children.
