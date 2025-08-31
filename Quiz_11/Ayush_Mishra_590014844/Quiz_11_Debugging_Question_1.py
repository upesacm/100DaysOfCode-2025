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
    return 1 + max(left_height, right_height)

# Test case 1:
#     1
#    /
#   2
#  /
# 3
root = TreeNode(1)
root.left = TreeNode(2)
root.left.left = TreeNode(3)
print(f"Height of tree: {tree_height(root)}")

# Test case 2:
#   1
#  / \
# 2   3
single_node = TreeNode(1)
print(f"Height of single node: {tree_height(single_node)}")
