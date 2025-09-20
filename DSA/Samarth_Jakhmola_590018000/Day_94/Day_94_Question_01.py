import bisect  # Provides binary search operation on sorted lists

def longest_increasing_subsequence(nums):
    sub = []  # stores the smallest possible tail of subsequences
    for x in nums:
        i = bisect.bisect_left(sub, x)  # binary search
        if i == len(sub):
            sub.append(x)   # extend LIS (longest increasing subsequence)
        else:
            sub[i] = x   # replace to maintain optimal tail
    return len(sub)

nums = list(map(int, input("Enter the elements of the array, separated by spaces : ").split()))
print(longest_increasing_subsequence(nums))
