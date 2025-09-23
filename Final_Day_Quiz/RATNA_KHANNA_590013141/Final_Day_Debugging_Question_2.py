#1) Bug in handling negative path contributions-The code uses left_sum and right_sum directly even when they are negative. 
#Negative subtree sums should be discarded because a parent can always choose not to include a negative branch.
#Fix: use left_gain = max(helper(node.left), 0) and right_gain = max(helper(node.right), 0).
#2) Why the helper return value is incorrect
#The helper currently returns node.val + left_sum + right_sum (i.e. sum through both children). 
#But a value returned to the parent must represent the maximum sum of a path starting at the current node and 
#going down into one side (or none). Returning the sum of both sides is not a valid single-direction extension and causes parents to 
#double-count or use invalid combined paths.
#3) Correct logic for the value returned to parent
#Compute:
left_gain  = max(helper(node.left),  0)
right_gain = max(helper(node.right), 0)
#Update global maximum with the best path through this node:
current_max = node.val + left_gain + right_gain
self.max_path_sum = max(self.max_path_sum, current_max)
#Return the maximum sum for a path that extends to the parent (choose the larger child or none):
return node.val + max(left_gain, right_gain)
