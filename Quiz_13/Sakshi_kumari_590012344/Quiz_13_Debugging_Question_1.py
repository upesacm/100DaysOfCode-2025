1. Identify the missing optimization that causes inefficiency.
The missing step is checking whether the current node has already been visited.
Without this, the same node can be added to the priority queue multiple times.

2. Explain why the algorithm still works but is not optimal:
    It still works because distances[] ensures that only shorter paths update the distance.
     Even if duplicate nodes are processed, outdated paths are ignored. But this leads
     to unnecessary extra pops from the priority queue.

3. What does it actually return and why might it be inefficient?
   It returns the CORRECT shortest distances dictionary, but may perform more work
     than necessary since multiple outdated entries for the same node remain in the queue.
     That makes the runtime worse than O((V+E) log V), especially in dense graphs.
