class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.max_sum = float("-inf")

    def max_path_sum_tree(self, root):
        def helper(node):
            if not node:
                return 0
            left = max(helper(node.left), 0)
            right = max(helper(node.right), 0)
            current = node.val + left + right
            if current > self.max_sum:
                self.max_sum = current
            return node.val + max(left, right)
        helper(root)
        return self.max_sum

if __name__ == "__main__":
    root = TreeNode(10)
    root.left = TreeNode(2)
    root.right = TreeNode(10)
    root.left.left = TreeNode(20)
    root.left.right = TreeNode(1)
    root.right.right = TreeNode(-25)
    root.right.right.left = TreeNode(3)
    root.right.right.right = TreeNode(4)

    sol = Solution()
    print("Maximum path sum:", sol.max_path_sum_tree(root))

"""
Answers:
1. Bug: negative path contributions were not ignored; negative sums from children should be clamped to 0.
2. The helper returned node.val + left + right which allows a forked path to be passed up to the parent; a parent can only extend one side, so returning both sides is incorrect.
3. Correct logic: compute left = max(helper(left), 0) and right = max(helper(right), 0). Update global max with node.val + left + right. Return node.val + max(left, right) so parent gets the best single-side extension.
"""
