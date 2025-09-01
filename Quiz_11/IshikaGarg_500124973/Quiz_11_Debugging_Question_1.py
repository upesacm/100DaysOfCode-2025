1 — Buggy line
return max(left_height, right_height)

2 — Why it’s wrong
Height (counting nodes) must include the current node at each level.
Without +1, leaves return 0, their parents also return 0, and the whole tree’s height collapses to 0 for any non-empty tree.

Corrected Code:
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def tree_height(root):
    """Return height measured in nodes (empty tree -> 0)."""
    if root is None:
        return 0
    left_height = tree_height(root.left)
    right_height = tree_height(root.right)
    return 1 + max(left_height, right_height)  # <-- fixed: include current node

# ---------- Tests ----------

# Test case 1 (skewed left)
#     1
#    /
#   2
#  /
# 3
root = TreeNode(1)
root.left = TreeNode(2)
root.left.left = TreeNode(3)

result = tree_height(root)
print(f"Height of tree: {result}")   # Expected: 3

# Test case 2 (single node)
single_node = TreeNode(1)
single_result = tree_height(single_node)
print(f"Height of single node: {single_result}")  # Expected: 1

# Test case 3 (root with two children)
#   1
#  / \
# 2   3
root2 = TreeNode(1)
root2.left = TreeNode(2)
root2.right = TreeNode(3)
print(f"Height of root2: {tree_height(root2)}")  # Expected: 2
