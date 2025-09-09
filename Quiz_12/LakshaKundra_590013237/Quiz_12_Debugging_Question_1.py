#answer 1
#The given code only checks the immediate children of a node (root.left.val < root.val and root.right.val > root.val).
#It does not ensure that all nodes in the left subtree are less than the current node and all nodes in the right subtree are greater than the current node.

#answer 2
#Because the code only enforces local constraints (parent vs. child) instead of the global BST property (entire subtree constraints).
#As a result, it passes trees where, A node in the right subtree is smaller than the root or a node in the left subtree is greater than the root.

#correct code:
class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def is_valid_bst(root):
    # Use bounds (low, high) to enforce global BST constraints
    def helper(node, low, high):
        if not node:
            return True
        if not (low < node.val < high):
            return False
        return helper(node.left, low, node.val) and helper(node.right, node.val, high)

    return helper(root, float('-inf'), float('inf'))


# Test case that reveals the bug:
#     10
#    /  \
#   5    15
#       /  \
#      6   20
root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(15)
root.right.left = TreeNode(6)
root.right.right = TreeNode(20)

result = is_valid_bst(root)
print(f"Is valid BST: {result}")  # Should print False (6 < 10)


# Another test case:
#     5
#    / \
#  1   4
#       / \
#      3   6
root2 = TreeNode(5)
root2.left = TreeNode(1)
root2.right = TreeNode(4)
root2.right.left = TreeNode(3)
root2.right.right = TreeNode(6)

result2 = is_valid_bst(root2)
print(f"Is valid BST: {result2}")  # Should print False
