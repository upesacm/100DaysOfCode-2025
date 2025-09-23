class Solution:
    def _init_(self):
        self.max_path_sum = float('-inf')
    
    def max_path_sum_tree(self, root):
        if not root:
            return 0
        
        def helper(node):
            if not node:
                return 0
          
            left_sum = max(0, helper(node.left))   
            right_sum = max(0, helper(node.right))
            
            current_path_sum = node.val + left_sum + right_sum
            
            self.max_path_sum = max(self.max_path_sum, current_path_sum)
            
        
            return node.val + max(left_sum, right_sum)
        helper(root)
        return self.max_path_sum
