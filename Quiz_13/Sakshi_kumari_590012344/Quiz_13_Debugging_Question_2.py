 1. Identify the bug in the result order:
    The function returns the nodes in reverse order of the correct topological sort.
This happens because each node is added to stack only after exploring its descendants.

 2. Explain why the stack needs to be reversed for correct topological order:
     DFS adds nodes to the stack after exploring all outgoing edges.
      So the stack ends up in "finishing time order". Reversing it gives the
correct topological order where each node comes before its dependencies.

3. What is the correct way to return the topologically sorted vertices?
    return stack[::-1]  (reverse the stack before returning).
