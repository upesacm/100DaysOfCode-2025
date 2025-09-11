1.  Identify the inefficiency in the current approach
The original code traversed BOTH left and right subtrees unconditionally.
This causes unnecessary work, especially for large trees where many branches can be skipped based on the range.

2. Why the algorithm doesn't utilize BST properties:
   A BST has ordering rules: 
   - Left subtree nodes < root
   - Right subtree nodes > root
   The buggy code ignores this fact and always explores both sides,
   turning the time complexity into O(n) for all cases.

3. Optimizations using BST characteristics:
   3. Optimization: we can skip useless branches.
   - if root < L → go right only
   - if root > R → go left only
   - else → include root and go both sides

This way we reduce extra work and make it much faster.
