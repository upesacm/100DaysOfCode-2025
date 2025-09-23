#   Test case result : It will return a small value because it includes negative contributions from -25 subtree and returns incorrect sums 
#                      upward.
# 
# 
#   1.  The code directly adds left_sum and right_sum to the node's value. If left_sum or right_sum is negative, it reduces the total
#       unnecessarily.  
# 
# 
#   2.  The function correctly returns node.val + left_sum + right_sum . This represents a path passing through both children, but 
#       recursion to the parent should only continue along one side (left or right), not both. Because of this, the recursion sends back
#       inflated sums, breaking the logic.
# 
# 
#   3.  The correct logic for choosing maximum path extending to parent should be :
#       - For updating the global max :
#           curremt_max = node.val + max(left_sum, 0) + max(right_sum, 0)  
#           (this allows the path to paas through the node using both sides if beneficial).
# 
#       - For returning to parent recursion : 
#           return node.val + max(max(left_sum, 0) + max(right_sum, 0))
#           (only one path can be extended upward to the parent). 
