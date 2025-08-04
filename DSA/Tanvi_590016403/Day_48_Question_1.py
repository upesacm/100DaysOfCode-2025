from collections import deque, Counter

# 1. Remove All Occurrences of an Element from a Queue
def remove_occurrences(queue, x):
    updated_queue = deque()
    for element in queue:
        if element != x:
            updated_queue.append(element)
    return list(updated_queue)

# 2. Check if All Elements in Queue are Unique
def are_elements_unique(queue):
    seen = set()
    for element in queue:
        if element in seen:
            return False
        seen.add(element)
    return True

# 3. Count Occurrences of Each Element in a Queue
def count_occurrences(queue):
    return dict(Counter(queue))

# ----------- Test Cases -----------

# Test 1: Remove Occurrences
print("1. Remove All Occurrences:")
print(remove_occurrences([1, 2, 3, 2, 4], 2))  # Output: [1, 3, 4]
print(remove_occurrences([5, 5, 5], 5))        # Output: []

# Test 2: Uniqueness Check
print("\n2. Check Uniqueness:")
print(are_elements_unique([1, 2, 3, 4]))       # Output: True
print(are_elements_unique([1, 2, 2, 3]))       # Output: False

# Test 3: Frequency Count
print("\n3. Count Occurrences:")
print(count_occurrences([1, 2, 2, 3, 1, 1]))   # Output: {1: 3, 2: 2, 3: 1}
print(count_occurrences([5, 5, 7, 8, 7]))      # Output: {5: 2, 7: 2, 8: 1}
