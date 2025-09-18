#1. Missing Optimization-
if current_node in visited:
    continue
visited.add(current_node)

#2.Why the Algorithm Still Works
# Despite the inefficiency, the algorithm still works correctly because:
# -It always updates a node’s distance only if a shorter path is found.
# -The priority queue ensures nodes with smaller distances are processed earlier.
# So even if a node is processed multiple times, the shortest path eventually gets recorded.

#3.Expected: {0: 0, 1: 3, 2: 1, 3: 4}..code still produces the correct result because heapq ensures shorter paths eventually bubble up.
# Nodes may be processed multiple times, even after their shortest path is finalized.
# This leads to redundant calculations and extra heap operations, especially in dense graphs.
