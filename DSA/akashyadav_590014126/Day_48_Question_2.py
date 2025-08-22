from collections import deque

def is_unique(queue):
    seen = set()
    while queue:
        element = queue.popleft()
        if element in seen:
            return False
        seen.add(element)
    return True

# Example usage
q1 = deque([21,22,23,24,21])
print(is_unique(q1))