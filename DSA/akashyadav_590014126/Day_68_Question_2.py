import heapq
from collections import Counter

def rearrange_string(s):
    freq = Counter(s)

    max_heap = [(-count, char) for char, count in freq.items()]
    heapq.heapify(max_heap)

    result = []
    prev_count, prev_char = 0, ''

    while max_heap:
        count, char = heapq.heappop(max_heap)
        result.append(char)

        if prev_count < 0:
            heapq.heappush(max_heap, (prev_count, prev_char))

        prev_count = count + 1  
        prev_char = char

    rearranged = ''.join(result)

    for i in range(1, len(rearranged)):
        if rearranged[i] == rearranged[i - 1]:
            return ""  

    return rearranged
