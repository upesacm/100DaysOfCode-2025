# 1. Display Elements of a Queue
# A problem that introduces fundamental queue traversal techniques and teaches non-destructive element access methods for queue inspection while preserving the original data structure integrity.

# Write a function to display all elements of a queue from front to rear without modifying the queue. This operation is fundamental in queue debugging and data structure inspection where you need to examine queue contents without affecting the underlying FIFO structure. The technique requires understanding non-destructive traversal methods that preserve queue state while providing visibility into stored elements. This concept is essential in system monitoring, debugging operations, and queue analysis where inspecting data flow without disruption is crucial for maintaining system stability and performance diagnostics.

# This teaches non-destructive traversal algorithms and queue inspection techniques that are essential for system debugging and efficient queue state analysis operations.

# Your task: Implement queue traversal that displays all elements in FIFO order while maintaining the original queue structure and state.

# Examples
# Input:

# Queue = [10, 20, 30]
# Output:

# 10 20 30
# Input:

# Queue = [5, 15]
# Output:

# 5 15
from queue import Queue

def display_queue(q: Queue):
    temp_queue = Queue()
    
    while not q.empty():
        item = q.get()
        print(item, end=' ')
        temp_queue.put(item)
    
    while not temp_queue.empty():
        q.put(temp_queue.get())

    print()