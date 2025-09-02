#answer 1
#the bug is in this line 
#root.val = left_sum + right_sum
#It assigns the node’s value as the sum of values returned by subtrees.

#answer 2
#Leaf nodes do become 0 temporarily, but since the function returns old_val + left_sum + right_sum, their original values get passed back up the recursion.
#This makes parent nodes include those original leaf values in their sums.
#Hence the final tree doesn’t match the intended “Sum Tree” definition.

#answer 3
# 1- Save the old value.
# 2- Recursively convert left and right.
# 3- Update root.val to be the sum of converted children.
# 4- Return the sum of the original subtree so the recursion works correctly.

#correct code
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def convert_to_sum_tree(root):
    if not root:
        return 0

    # Save old value before updating
    old_val = root.val

    # Recursively convert left & right subtrees
    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)

    # Update current node to sum of left + right subtree values
    root.val = left_sum + right_sum

    # Return total sum of subtree including old value
    return root.val + old_val


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
