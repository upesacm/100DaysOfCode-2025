def max_sliding_window(arr, k):
    left, right = [], []
    n = len(arr)
    res = []
    for i in range(n):
        if i % k == 0:
            left = []
            for j in range(k):
                if i + j < n:
                    while left and arr[i + j] > left[-1]:
                        left.pop()
                    left.append(arr[i + j])
        res.append(left[0])
        if i + k < n:
            if arr[i] == left[0]:
                left.pop(0)
            while left and arr[i + k] > left[-1]:
                left.pop()
            left.append(arr[i + k])
    return res[:n - k + 1]

print(max_sliding_window([1, 3, -1, -3, 5, 3, 6, 7], 3))
print(max_sliding_window([4, 2, 1, 5], 2))
