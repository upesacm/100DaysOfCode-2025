# Rearrange Characters (Greedy Frequency)
import heapq
from collections import Counter
s = input()
freq = Counter(s)
max_heap = [(-cnt, ch) for ch, cnt in freq.items()]
heapq.heapify(max_heap)
prev = (0, "")
res = []
while max_heap:
    cnt, ch = heapq.heappop(max_heap)
    res.append(ch)
    if prev[0] < 0:
        heapq.heappush(max_heap, prev)
    prev = (cnt + 1, ch)
print("".join(res) if len(res) == len(s) else "")
