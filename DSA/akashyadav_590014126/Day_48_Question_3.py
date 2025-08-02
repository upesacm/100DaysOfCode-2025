from collections import deque

def count_frequencies(queue):
    freq_map = {}
    while queue:
        element = queue.popleft()
        if element in freq_map:
            freq_map[element] += 1
        else:
            freq_map[element] = 1
    return freq_map

# Example usage
q = deque([21,22,21,23,21,24,25])
print(count_frequencies(q))
