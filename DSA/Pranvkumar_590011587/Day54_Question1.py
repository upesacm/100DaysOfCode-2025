def three_sum(nums, target=0):
    nums.sort()
    n = len(nums)
    res = []
    for i in range(n-2):
        if i > 0 and nums[i] == nums[i-1]:
            continue  # Avoid duplicate triplets
        left, right = i+1, n-1
        while left < right:
            total = nums[i] + nums[left] + nums[right]
            if total == target:
                res.append([nums[i], nums[left], nums[right]])
                left += 1
                right -= 1
                while left < right and nums[left] == nums[left-1]: left += 1
                while left < right and nums[right] == nums[right+1]: right -= 1
            elif total < target:
                left += 1
            else:
                right -= 1
    return res

# Example Usage
print(three_sum([-1, 0, 1, 2, -1, -4]))       
print(three_sum([0, 1, 1]))                    