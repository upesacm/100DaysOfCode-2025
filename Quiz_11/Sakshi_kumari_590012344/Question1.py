1. Identify the specific line(s) causing the bug
The bug is in the return statement:
return max(left_height, right_height)

2. Why it causes incorrect behavior
The function does not add 1 for the current root node.
So, it only returns the height of the taller subtree, ignoring the contribution of the current node.
    1
   /
  2
 /
3
Correct height = 3 (nodes 1 → 2 → 3).
This function calculates:
At node 3: left = 0, right = 0 → returns max(0, 0) = 0
At node 2: left = 0, right = 0 → returns 0
At node 1: left = 0, right = 0 → returns 0
Incorrect result = 0
It should have been:
return 1 + max(left_height, right_height
so that each recursive call adds the current node to the height count.

Here is the corrected code:-
    def tree_height(root):
    if root is None:
        return 0
    left_height = tree_height(root.left)
    right_height = tree_height(root.right)
    return 1 + max(left_height, right_height)
                
