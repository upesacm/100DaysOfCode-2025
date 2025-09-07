#  1.  The current approach traverses both left and right subtrees, even when node values are clearly outside the range [L, R].
  
  
#  2.  In a BST, left node < root < right node.
#      If root.val < L, left subtree can be skipped.
#      If root.val > R, right subtree can be skipped.
#      The current code ignores this and explores useless branches.
  
  
#  3.  If root.val > R -> only search left subtree.
#      If root.val < L -> only search right subtree.
#      Else (within range) -> add root.val and search both sides. 
#      This reduces unnecessary traversal, improving efficiency.
