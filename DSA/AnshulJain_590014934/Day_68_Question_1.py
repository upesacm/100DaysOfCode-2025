arr = list(map(int, input("Enter The array:").split()))
n = len(arr)
if n <= 1:
    print(0)
else:
    jumps, farthest, end = 0, 0, 0
    for i in range(n - 1):
        farthest = max(farthest, i + arr[i])
        if i == end:
            jumps += 1
            end = farthest
            if end >= n - 1:
                break
    print(jumps)
