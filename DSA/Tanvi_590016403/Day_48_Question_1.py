from collections import deque, Counter

# 1. Remove all occurrences of a value from the queue
def remove_all_occurrences(queue, x):
    updated_queue = deque([item for item in queue if item != x])
    return list(updated_queue)

# 2. Check if all elements in the queue are unique
def all_unique(queue):
    seen = set()
    for item in queue:
        if item in seen:
            return False
        seen.add(item)
    return True

# 3. Count occurrences of each element in the queue
def count_occurrences(queue):
    frequency = Counter(queue)
    return dict(frequency)

# ------------------ Example Usage ------------------
q1 = deque([1, 2, 3, 2, 4])
print("After Removing 2:", remove_all_occurrences(q1, 2))  # Output: [1, 3, 4]

q2 = deque([1, 2, 3, 4])
print("All Unique?:", all_unique(q2))  # Output: True

q3 = deque([1, 2, 2, 3, 1, 1])
print("Occurrences Count:", count_occurrences(q3))  # Output: {1: 3, 2: 2, 3: 1}
