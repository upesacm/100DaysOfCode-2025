import bisect

def lengthOfLIS_nlogn(nums):
    sub = []
    for num in nums:
        idx = bisect.bisect_left(sub, num)
        if idx == len(sub):
            sub.append(num)
        else:
            sub[idx] = num
    return len(sub)

print(lengthOfLIS_nlogn([10, 9, 2, 5, 3, 7, 101, 18]))  # Output: 4
print(lengthOfLIS_nlogn([0, 1, 0, 3, 2, 3]))            # Output: 4
