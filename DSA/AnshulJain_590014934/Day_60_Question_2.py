import heapq

n = list(map(int, input().split()))
low, high = [], []

def add_num(num):
    if not low or num <= -low[0]:
        heapq.heappush(low, -num)
    else:
        heapq.heappush(high, num)
    if len(low) > len(high) + 1:
        heapq.heappush(high, -heapq.heappop(low))
    elif len(high) > len(low):
        heapq.heappush(low, -heapq.heappop(high))

def find_median():
    if len(low) > len(high):
        return -low[0]
    return (-low[0] + high[0]) // 2

for x in n:
    add_num(x)
    print(find_median(), end=" ")
#for example:
# input: 5 15 1 3
# output: 5 10 5 4