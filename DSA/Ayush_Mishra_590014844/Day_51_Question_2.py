def smallest_subarray_sum_gt_x(arr, x):
    left = 0
    sum_ = 0
    min_len = len(arr) + 1

    for right in range(len(arr)):
        sum_ += arr[right]
        while sum_ > x:
            min_len = min(min_len, right - left + 1)
            sum_ -= arr[left]
            left += 1
    return min_len if min_len <= len(arr) else 0

arr = list(map(int, input().split()))
x = int(input())
print(smallest_subarray_sum_gt_x(arr, x))
