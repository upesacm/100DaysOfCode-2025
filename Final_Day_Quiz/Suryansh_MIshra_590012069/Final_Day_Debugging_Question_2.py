class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def max_path_sum_tree(self, root):
        # global answer can start at -inf to handle all-negative trees
        self.ans = float("-inf")

        def gain(node):
            if not node:
                return 0
            # ignore negative paths
            left = max(0, gain(node.left))
            right = max(0, gain(node.right))

            # best path that 'passes through' this node
            self.ans = max(self.ans, node.val + left + right)

            # return best one-side path to parent
            return node.val + max(left, right)

        gain(root)
        return self.ans
