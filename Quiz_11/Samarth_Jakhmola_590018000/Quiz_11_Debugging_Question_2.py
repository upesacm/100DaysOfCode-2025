#  1.  The main issue is that there is no explicit check for leaf nodes, so they aren't directly set to 0. The code works due to calculation
#      but explicit logic makes it clearer.
#  
#  2.  Leaf nodes temporarily retain old values since there is no condition to set them to 0.
#  
#      Correct implementation : 
#  
#      class TreeNode:
#          def __init__(self, val=0, left=None, right=None):
#              self.val = val
#              self.left = left
#              self.right = right
#      
#      
#      def convert_to_sum_tree(root):
#          if not root:
#              return 0
#      
#          old_val = root.val
#      
#          left_sum = convert_to_sum_tree(root.left)
#          right_sum = convert_to_sum_tree(root.right)
#      
#          root.val = left_sum + right_sum
#      
#          return root.val + old_val  # Return total sum for parent's calculation.
#      
#      
#      # Test case:
#      #     1
#      #    / \
#      #   2   3
#      #  / \
#      # 4   5
#      root = TreeNode(1)
#      root.left = TreeNode(2)
#      root.right = TreeNode(3)
#      root.left.left = TreeNode(4)
#      root.left.right = TreeNode(5)
#      
#      
#      def print_inorder(root):
#          if root:
#              print_inorder(root.left)
#              print(root.val, end=" ")
#              print_inorder(root.right)
#      
#      
#      print("Original tree (inorder):")
#      print_inorder(root)
#      print()
#      
#      convert_to_sum_tree(root)
#      print("After conversion (inorder):")
#      print_inorder(root)
#      print()
