def heapify(a, n, i):
    l = i
    left = 2 * i + 1
    right = 2 * i + 2
    if left < n and a[left] > a[l]:
        l = left
    if right < n and a[right] > a[l]:
        l = right
    if l != i:
        a[i], a[l] = a[l], a[i]
        heapify(a, n, l)
a = list(map(int, input().split()))
n = len(a)
for i in range(n // 2 - 1, -1, -1):
    heapify(a, n, i)
print(a)
