class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def convert_to_sum_tree(root):
    if not root:
        return 0

    old_val = root.val

    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)

    root.val = left_sum + right_sum   # LOGICAL ERROR

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

convert_to_sum_tree(root)
print("After conversion (inorder):")
print_inorder(root)
print()

#anwer of task Question:-
# 1. Wrong logic: root.val = left_sum + right_sum assigns only children’s sums, ignoring that leaf nodes should become 0.
# 2. Leaf nodes don’t become 0 because their values are replaced with the sum of recursive calls (which return 0 for both left and right), but the function still adds old_val when returning upward.
# 3. Correct implementation:
# def convert_to_sum_tree(root):
#     if not root:
#         return 0
#     old_val = root.val
#     root.val = convert_to_sum_tree(root.left) + convert_to_sum_tree(root.right)
#     return root.val + old_val
