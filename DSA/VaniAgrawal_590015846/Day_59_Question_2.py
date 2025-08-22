# Implement max-heap functionality using priority queue libraries with proper element insertion and maximum extraction operations.
import heapq, re

line = input().strip()
line = line.replace('→', '->')

nums = list(map(int, re.findall(r'-?\d+', line.split('->')[0])))
ops  = [part.strip().lower() for part in line.split('->')[1:]]

h = []
for x in nums:
    heapq.heappush(h, -x)

k = sum('extractmax' in op for op in ops)

out = []
for _ in range(k):
    if h:
        out.append(str(-heapq.heappop(h)))

print(", ".join(out))
