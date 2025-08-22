def binary_subarray_sum(nums, goal):
    prefix_sum = 0
    prefix_count = {0: 1} 
    count = 0

    for num in nums:
        prefix_sum += num
        if (prefix_sum - goal) in prefix_count:
            count += prefix_count[prefix_sum - goal]

        prefix_count[prefix_sum] = prefix_count.get(prefix_sum, 0) + 1

    return count

print(binary_subarray_sum([1,0,1,0,1], 2)) 
print(binary_subarray_sum([0,0,0,0,0], 0)) 
