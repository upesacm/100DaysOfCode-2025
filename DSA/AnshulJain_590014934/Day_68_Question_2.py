import heapq
s = input("Enter The array:").strip()
freq = {}
for c in s:
    freq[c] = freq.get(c, 0) + 1
heap = [(-v, k) for k, v in freq.items()]
heapq.heapify(heap)
res = []
prev = (0, '')
while heap:
    v, c = heapq.heappop(heap)
    res.append(c)
    if prev[0] < 0:
        heapq.heappush(heap, prev)
    prev = (v + 1, c)
ans = ''.join(res)
print(ans if len(ans) == len(s) else "")
