#he Bug in the Result Order-Current code appends each node to the stack after exploring all its neighbors (post-order).
#2.Topological sort requires dependencies first, dependents later.DFS appends nodes after finishing neighbors → gives a reverse topological order.
#To fix: reverse the stack before returning.
#3.Correct Way to Return the Sorted Vertices-return stack[::-1]
