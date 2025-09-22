class Node:
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.max_sum = float('-inf')

    def maxPathSum(self, root):
        def max_gain(node):
            if node is None:
                return 0

            left_gain = max(max_gain(node.left), 0)
            right_gain = max(max_gain(node.right), 0)

            path_sum = node.val + left_gain + right_gain

            if path_sum > self.max_sum:
                self.max_sum = path_sum

            return node.val + max(left_gain, right_gain)

        max_gain(root)
        return self.max_sum
