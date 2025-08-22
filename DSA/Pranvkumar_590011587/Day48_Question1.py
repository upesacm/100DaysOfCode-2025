from collections import deque
def remove_all_occurrences(queue, x):
    result = deque()
    while queue:
        item = queue.popleft()
        if item != x:
            result.append(item)
    return list(result)  # or return deque if you want to keep it as a queue

# Examples:
print(remove_all_occurrences(deque([1,2,3,2,4]), 2))      
print(remove_all_occurrences(deque([5,5,5]), 5))         