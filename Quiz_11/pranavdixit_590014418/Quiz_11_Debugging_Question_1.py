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

    return max(left_height, right_height)   # BUG HERE


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

#answer of task Question:-
# 1. Buggy line: return max(left_height, right_height)
# 2. Reason: It does not count the current root node level, so the computed height is always 1 less than the actual height.
