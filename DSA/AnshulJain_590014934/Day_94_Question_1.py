def lis_length(nums):
    from bisect import bisect_left
    sub = []
    for x in nums:
        i = bisect_left(sub, x)
        if i == len(sub):
            sub.append(x)
        else:
            sub[i] = x
    return len(sub)
arr = list(map(int, input("Enter array elements separated by space: ").split()))
print(lis_length(arr))
