from collections import deque

def find_minimum(queue):
    min_val = float('inf')
    for item in queue:
        if item < min_val:
            min_val = item
    return min_val

# Example usage:
q = deque([4, 2, 7, 1])
result = find_minimum(q)  
print(result)