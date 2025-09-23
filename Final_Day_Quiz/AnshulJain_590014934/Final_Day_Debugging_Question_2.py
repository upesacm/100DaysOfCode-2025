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

            left_sum = max(helper(node.left), 0)
            right_sum = max(helper(node.right), 0)

            current_max = node.val + left_sum + right_sum
            self.max_path_sum = max(self.max_path_sum, current_max)

            return node.val + max(left_sum, right_sum)

        helper(root)
        return self.max_path_sum


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

# Task answers:
# 1. Bug: Negative path sums were added directly, reducing overall path value; they should be discarded by taking max(child_sum, 0).
# 2. The helper return value was incorrect because it returned node.val + left_sum + right_sum, which allows two branches upward; for recursion, only one side plus node should propagate.
# 3. Correct logic: return node.val + max(left_sum, right_sum) so only the best single path extends to the parent.
