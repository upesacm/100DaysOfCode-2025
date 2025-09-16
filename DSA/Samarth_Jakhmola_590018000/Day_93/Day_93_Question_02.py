def max_subarray_sum(nums):
    current_sum = nums[0]
    max_sum = nums[0]

    for i in range(1, len(nums)):
        current_sum =  max(nums[i], nums[i] + current_sum)
        max_sum = max(max_sum, current_sum)

    return max_sum

nums = list(map(int, input("Enter the elements of te array, separated by spaces : ").split()))
print(max_subarray_sum(nums))
