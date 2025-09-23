class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.max_path_sum = float("-inf")

    def max_path_sum_tree(self, root):
        if not root:
            return 0

        def helper(node):
            if not node:
                return 0

            # Get maximum sum from left and right subtrees
            left_sum = helper(node.left)
            right_sum = helper(node.right)

            # Fix 1: Ignore negative paths
            left = max(0, left_sum)
            right = max(0, right_sum)

            # Fix 2: Correct full path sum through current node
            current_max = node.val + left + right
            self.max_path_sum = max(self.max_path_sum, current_max)

            # Fix 3: Return max path extending to parent
            return node.val + max(left, right)

        helper(root)
        return self.max_path_sum


# Test case:
#     10
#    /  \
#   2    10
#  / \     \
# 20  1    -25
#           / \
#          3   4

root = TreeNode(10)
root.left = TreeNode(2)
root.right = TreeNode(10)
root.left.left = TreeNode(20)
root.left.right = TreeNode(1)
root.right.right = TreeNode(-25)
root.right.right.left = TreeNode(3)
root.right.right.right = TreeNode(4)

solution = Solution()
result = solution.max_path_sum_tree(root)
print(f"Maximum path sum: {result}")
# Expected: 42 (path: 20 → 2 → 10 → 10)
# Ensure negative paths are ignored to avoid lowering the maximum path sum
