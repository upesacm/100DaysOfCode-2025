class Solution:
    def __init__(self):
        self.max_path_sum = float("-inf")

    def max_path_sum_tree(self, root):
        if not root:
            return 0

        def helper(node):
            if not node:
                return 0

            # Fix: clamp negative contributions to 0
            left_sum = max(0, helper(node.left))   # was: left_sum = helper(node.left)
            right_sum = max(0, helper(node.right)) # was: right_sum = helper(node.right)

            # path that uses both sides through node
            current_max = node.val + left_sum + right_sum

            self.max_path_sum = max(self.max_path_sum, current_max)

            # Fix: return the best single-side path that can extend to parent
            return node.val + max(left_sum, right_sum)  # was: return node.val + left_sum + right_sum

        helper(root)
        return self.max_path_sum
