class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def range_sum_bst(root, L, R):
    if not root:
        return 0
    if root.val < L:
        return range_sum_bst(root.right, L, R)
    if root.val > R:
        return range_sum_bst(root.left, L, R)
    return root.val + range_sum_bst(root.left, L, R) + range_sum_bst(root.right, L, R)

# Task 1: Identify the specific flaw in the validation logic
# The original code does not skip unnecessary branches and does not efficiently prune the search space according to the BST property.

# Task 2: Why this causes incorrect behavior
# The original logic traverses all nodes regardless of their relevance to the range, causing inefficiency and potentially incorrect sums if irrelevant nodes are included.

# Correct implementation ensures pruning by comparing node values with L and R and only traversing relevant subtrees.

root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(15)
root.left.left = TreeNode(3)
root.left.right = TreeNode(7)
root.right.right = TreeNode(18)

L = 7
R = 15

result = range_sum_bst(root, L, R)
print(f"Range sum is: {result}")
