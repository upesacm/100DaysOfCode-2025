from collections import deque

def remove_all_occurrences(queue, x):
    filtered_queue = deque()
    while queue:
        element = queue.popleft()
        if element != x:
            filtered_queue.append(element)
    return list(filtered_queue)

# Example usage
original_queue = deque([33,34,35,36,34,38])
x = 35
print(remove_all_occurrences(original_queue, x))  
