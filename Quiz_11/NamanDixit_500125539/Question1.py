#1. Bug in code - return max(left_height, right_height)

#2. Reason - Right now, the function does not add 1 for the current node. Because the +1 is missing, the height reported will always be off by one.
#Corrected code:-
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
print(f"Height of tree: {result}")

# Another test case:
#   1
#  / \
# 2   3
single_node = TreeNode(1)
single_result = tree_height(single_node)
print(f"Height of single node: {single_result}")
