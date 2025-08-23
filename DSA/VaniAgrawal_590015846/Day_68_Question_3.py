# Max Sum After K Negations
arr = list(map(int, input().split()))
k = int(input())
arr.sort()
i = 0
while i < len(arr) and k > 0 and arr[i] < 0:
    arr[i] = -arr[i]
    i += 1
    k -= 1
arr.sort()
if k % 2 == 1:
    arr[0] = -arr[0]
print(sum(arr))
