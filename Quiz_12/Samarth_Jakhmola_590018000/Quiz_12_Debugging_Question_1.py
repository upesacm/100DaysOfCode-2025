#  1.  The code only checks immediate children of a node, not the entire subtree against the valid BST range.count
  

#  2.  Example - node 6 is in the right subtree of 10 but still < 10. 
#      The code doesn't catch this since it compares 6 only with its parent (15), not with 10. Similarly, deeper violations are missed because
#      no minimum or maximum bounds are tracked.
