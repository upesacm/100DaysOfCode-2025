# Implement complete min-heap with insert and extractMin operations using array representation and proper heap property maintenance algorithms.
import heapq, re

line = input().strip()

line = line.replace('→', '->')

nums = list(map(int, re.findall(r'-?\d+', line.split('->')[0])))
ops  = [part.strip().lower() for part in line.split('->')[1:]]

h = []
for x in nums:
    heapq.heappush(h, x)

k = sum('extractmin' in op for op in ops)

out = []
for _ in range(k):
    if h:
        out.append(str(heapq.heappop(h)))

print(", ".join(out))
