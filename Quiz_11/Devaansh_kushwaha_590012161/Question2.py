class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def convert_to_sum_tree(root):
    if root is None:
        return 0

    old_val = root.val

    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)

    # Correct update: node becomes sum of left & right subtree sums
    root.val = left_sum + right_sum

    return root.val + old_val

def print_inorder(root):
    if root:
        print_inorder(root.left)
        print(root.val, end=" ")
        print_inorder(root.right)

# Test case
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
