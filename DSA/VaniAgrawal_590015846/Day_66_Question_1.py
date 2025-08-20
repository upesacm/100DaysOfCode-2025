#  Implement greedy platform allocation using event-based chronological processing to minimize required platforms while ensuring no scheduling conflicts.
n = int(input())
arr = list(map(int, input().split()))
dep = list(map(int, input().split()))
arr.sort()
dep.sort()
i = j = 0
platforms = result = 0
while i < n and j < n:
    if arr[i] <= dep[j]:
        platforms += 1
        result = max(result, platforms)
        i += 1
    else:
        platforms -= 1
        j += 1
print(result)
