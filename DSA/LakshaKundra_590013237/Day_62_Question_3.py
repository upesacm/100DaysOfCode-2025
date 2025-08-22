import heapq

def kth_largest_sum(arr, k):
    n = len(arr)
    sums = []
    for i in range(n):
        s = 0
        for j in range(i, n):
            s += arr[j]
            sums.append(s)
    return heapq.nlargest(k, sums)[-1]

print(kth_largest_sum([10, -10, 20, -40], 3))
print(kth_largest_sum([1, 2, 3], 2))
