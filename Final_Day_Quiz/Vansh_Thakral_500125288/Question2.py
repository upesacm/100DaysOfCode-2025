Task 1: Bug in handling negative paths
If left_sum = -5, adding it to node.val drags the path sum down.
Correct logic: left_sum = max(0, helper(node.left)) and similarly for right_sum.
This way, negative paths are discarded (treated as 0).

Task 2: Why return value is incorrect
Returning node.val + left_sum + right_sum means the parent "inherits both branches". That would create a "Y-shaped path", which isn’t valid for the recursive extension.
Parent should only extend one single path (either left or right).
                                                                                                                                    
                                                                                                                                           
class Solution:
    def __init__(self):
        self.max_path_sum = float("-inf")

    def max_path_sum_tree(self, root):
        def helper(node):
            if not node:
                return 0

            left_sum = max(0, helper(node.left))
            right_sum = max(0, helper(node.right))

            current_max = node.val + left_sum + right_sum
            self.max_path_sum = max(self.max_path_sum, current_max)

            return node.val + max(left_sum, right_sum)

        helper(root)
        return self.max_path_sum


                                                                                                                                           
