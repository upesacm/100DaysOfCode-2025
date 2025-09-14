#   1. The function return the stack as it is, which gives the reverse order of the correct topological order.

#   2. The nodes are appended after exploring all dependencies (post-order). This means that dependencies come earlier in the stack, so
#      reversing gives the right order.

#   3. Returning stack[::-1] instead of stack is the correct way to return the topologically sorted vertices.
