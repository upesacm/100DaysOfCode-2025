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

    # BUG: The line below was the problem
    # return max(left_height, right_height)
    # This is wrong because it only looks at the tallest subtree
    # and completely ignores the current node. 
    # That’s why the height ends up being off by one.
    return max(left_height, right_height) + 1  # Adding +1 fixes it


# Test case that shows the bug clearly:
#     1
#    /
#   2
#  /
# 3
root = TreeNode(1)
root.left = TreeNode(2)
root.left.left = TreeNode(3)

result = tree_height(root)
print(f"Height of tree: {result}")  # Should print 3

# Another simple test case:
#   1
#  / \
# 2   3
single_node = TreeNode(1)
single_result = tree_height(single_node)
print(f"Height of single node: {single_result}")  # Should print 1
