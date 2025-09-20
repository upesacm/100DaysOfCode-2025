#1. Missing Optimization-
if current_node in visited:
    continue
visited.add(current_node)
#2.Why the Algorithm Still Works
#Even without the visited set, the code keeps relaxing edges.If a shorter distance is found later, it updates distances[neighbor] 
#and pushes the new pair into the priority queue.This guarantees correctness because the smallest distances eventually propagate 
#and overwrite longer ones.However, unnecessary relaxations happen because the same node may be processed multiple times.
#3.Expected: {0: 0, 1: 3, 2: 1, 3: 4}..code still produces the correct result because heapq ensures shorter paths eventually bubble up.
#It Is Inefficient because without the visited check, nodes can be pushed multiple times into the priority queue (with outdated distances).
#This makes the complexity closer to O(E log E) instead of the optimal O(E log V).
