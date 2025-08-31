# 1. Buggy logic in the code:
#     root.val = left_sum + right_sum
#
# 2. Why this causes incorrect behavior:
# The definition of a Sum Tree states:
#   - Each node's value should become the sum of values of its left and right subtrees
#   - A leaf node should become 0
#
# In the buggy code:
#   - root.val is directly set to left_sum + right_sum
#   - BUT left_sum and right_sum already include the children's old values
#   - Therefore, leaf nodes incorrectly keep their old values (they don’t become 0)
#
# Example:
#     2 (leaf) → should become 0
#     But buggy code sets it as old_val (since no children) → stays as 2
#
# 3. Corrected Code:

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def convert_to_sum_tree(root):
    """
    Convert a binary tree to a Sum Tree:
    - Each node's value becomes the sum of values of its left and right subtrees.
    - Leaf nodes become 0.
    Returns the total sum of the subtree including the original node value.
    """
    if root is None:
        return 0

    # Save original value
    old_val = root.val

    # Recursively convert left and right subtrees
    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)

    # Update current node's value:
    # It should hold sum of left and right subtrees' original values
    root.val = left_sum + right_sum

    # Return sum of subtree including the original node value
    return root.val + old_val


# ---------------- TESTING ----------------

def print_inorder(root):
    if root:
        print_inorder(root.left)
        print(root.val, end=" ")
        print_inorder(root.right)


# Test Case 1: General tree
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
print("After conversion to Sum Tree (inorder):")
print_inorder(root)
print("\nExpected inorder: 0 9 0 20 0")  # ✅


# Test Case 2: Single node
single = TreeNode(10)
convert_to_sum_tree(single)
print("\nHeight-1 tree (single node → leaf):", single.val)
# Expected: 0


# Test Case 3: Empty tree
empty = None
print("Empty tree:", convert_to_sum_tree(empty))  # Expected: 0


# Test Case 4: Skewed Left tree
#   5
#  /
# 3
# /
# 1
skewed = TreeNode(5)
skewed.left = TreeNode(3)
skewed.left.left = TreeNode(1)
convert_to_sum_tree(skewed)
print("Inorder of skewed left tree after conversion:", end=" ")
print_inorder(skewed)
print("\nExpected inorder: 0 1 4")  # ✅


# Test Case 5: Right-skewed tree
# 7
#  \
#   2
#    \
#     1
right_skewed = TreeNode(7)
right_skewed.right = TreeNode(2)
right_skewed.right.right = TreeNode(1)
convert_to_sum_tree(right_skewed)
print("Inorder of skewed right tree after conversion:", end=" ")
print_inorder(right_skewed)
print("\nExpected inorder: 0 1 3")  # ✅
