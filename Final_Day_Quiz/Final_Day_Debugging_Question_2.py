class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.max_path_sum = float("-inf")

    def max_path_sum_tree(self, root):
        def helper(node):
            if not node:
                return 0

            # Get max path sum from left and right, ignore negative contributions
            left = max(helper(node.left), 0)
            right = max(helper(node.right), 0)

            # Max path **through** this node (including both left and right)
            current_max = node.val + left + right

            # Update the global max path sum
            self.max_path_sum = max(self.max_path_sum, current_max)

            # Return max path **extending to parent** (can only take one side)
            return node.val + max(left, right)

        helper(root)
        return self.max_path_sum


# --------------------------
# 🔍 Test case:
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
print(f"✅ Maximum path sum: {result}")  # Expected: 42 (20 → 2 → 10 → 10)

