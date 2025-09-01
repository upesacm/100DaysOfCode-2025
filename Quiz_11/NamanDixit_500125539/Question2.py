#1. root.val = left_sum + right_sum
#In a Sum Tree, each node’s value should become the sum of the values of its left and right subtrees
#in the original tree, not including itself.
#current recursion works, but it doesn’t handle leaf nodes correctly (they should become 0).

#2. When a leaf (e.g., 4) is processed, both children return 0, so its value is set to 0.
#However, the function then returns old_val + ... (which is 4), so the parent still includes
#the leaf’s original value in its sum.

#3. Corrected code. 
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def convert_to_sum_tree(root):
    if root is None:
        return 0

    # Save original value of current node
    old_val = root.val

    # Recursively convert left and right subtrees
    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)

    # Update current node’s value to sum of left + right subtree values
    root.val = left_sum + right_sum

    # Return sum of subtree including old value (for parent’s calculation)
    return old_val + root.val

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
