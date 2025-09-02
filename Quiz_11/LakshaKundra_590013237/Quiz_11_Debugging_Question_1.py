#answer 1
#The bug is in this line inside tree_height:
#return max(left_height, right_height)

#answer 2
#This line only returns the maximum depth of the left or right subtree.
#It does not include the current node itself in the height calculation.
#As a result, the computed height will always be 1 less than the actual height

#correct code 
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

    # ✅ Fix: add 1 for the current node
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

result = tree_height(root)
print(f"Height of tree: {result}")  # Expected: 3


# Test case 2:
#   1
#  / \
# 2   3
single_node = TreeNode(1)
single_result = tree_height(single_node)
print(f"Height of single node: {single_result}")  # Expected: 1
