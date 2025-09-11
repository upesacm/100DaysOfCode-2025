Identify the specific flaw in the validation logic 
The old code only checked the *immediate children* of a node.
  It did not enforce the full BST rule that:
  "All nodes in the left subtree must be < root,
  and all nodes in the right subtree must be > root."

Why this causes incorrect behavior:
 Because a node can appear valid when compared to its parent,
    but still break the BST property with respect to ancestors.
   Example: In the first test case, 6 is a left child of 15
    (so old code saw 6 < 15 and allowed it), but 6 is also in the
  right subtree of 10 , where it should be > 10. This violation
   was not detected in the buggy version.
