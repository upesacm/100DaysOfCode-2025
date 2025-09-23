class Solution:
    def _init_(self):
        self.max_path_sum = float('-inf')
    
    def max_path_sum_tree(self, root):
        if not root:
            return 0
        
        def helper(node):
            if not node:
                return 0
            
            # Get maximum sum from subtrees, ignore negative contributions
            left_sum = max(0, helper(node.left))   # Ignore negative paths
            right_sum = max(0, helper(node.right)) # Ignore negative paths
            
            # Maximum path sum passing through current node
            current_path_sum = node.val + left_sum + right_sum
            
            # Update global maximum
            self.max_path_sum = max(self.max_path_sum, current_path_sum)
            
            # Return maximum path sum that can extend to parent
            # Parent can only use one path (left or right), not both
            return node.val + max(left_sum, right_sum)
        
        helper(root)
        return self.max_path_sum
