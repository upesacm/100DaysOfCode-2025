from collections import deque

def remove_all_occurrences(queue, x):
    new_queue = deque()
    for item in queue:
        if item != x:
            new_queue.append(item)
    return list(new_queue)

print(remove_all_occurrences([1, 2, 3, 2, 4], 2))
print(remove_all_occurrences([5, 5, 5], 5))
