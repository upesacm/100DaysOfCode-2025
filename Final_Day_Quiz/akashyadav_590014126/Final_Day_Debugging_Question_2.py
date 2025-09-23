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

            left_sum = helper(node.left)
            right_sum = helper(node.right)

            left_sum = max(left_sum, 0)
            right_sum = max(right_sum, 0)

            current_max = node.val + left_sum + right_sum

            self.max_path_sum = max(self.max_path_sum, current_max)

            return node.val + max(left_sum, right_sum)

        helper(root)
        return self.max_path_sum

#1.Bug is not handling negative path sums; should ignore negative sums using max(left_sum, 0).
#2.Return value is incorrect because it sums both left and right for parent,
#but parent can extend path only along one child.
#3.Correct logic is to return node.val + max(left_sum, right_sum).
