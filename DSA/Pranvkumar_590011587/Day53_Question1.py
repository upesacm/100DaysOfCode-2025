def findMaxConsecutiveOnes(nums):
    max_count = cur_count = 0
    for num in nums:
        if num == 1:
            cur_count += 1
            max_count = max(max_count, cur_count)
        else:
            cur_count = 0
    return max_count

print(findMaxConsecutiveOnes([1, 1, 0, 1, 1, 1]))  
print(findMaxConsecutiveOnes([1, 0, 1, 1, 0, 1])) 