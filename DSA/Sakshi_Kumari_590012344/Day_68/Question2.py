import heapq

def rearrange_string(s):
    freq = {}
    for ch in s:
        freq[ch] = freq.get(ch, 0) + 1
    max_heap = [(-count, ch) for ch, count in freq.items()]
    heapq.heapify(max_heap)
    prev = (0, '')
    result = []
    while max_heap:
        count, ch = heapq.heappop(max_heap)
        result.append(ch)
        if prev[0] < 0:
            heapq.heappush(max_heap, prev)
        count += 1
        prev = (count, ch)
    result_str = ''.join(result)
    if len(result_str) != len(s):
        return ""
    return result_str
