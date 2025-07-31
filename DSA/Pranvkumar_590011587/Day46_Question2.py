from collections import deque

def count_even_odd(queue):
    even = 0
    odd = 0
    for item in queue:
        if item % 2 == 0:
            even += 1
        else:
            odd += 1
    return even, odd

# Example usage:
q = deque([1, 2, 3, 4, 5])
even, odd = count_even_odd(q)
print(even,odd) 