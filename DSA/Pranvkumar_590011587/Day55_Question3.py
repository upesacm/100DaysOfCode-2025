def num_subarrays_with_sum(nums, goal):
    from collections import defaultdict
    prefix_counts = defaultdict(int)
    prefix_counts[0] = 1
    curr_sum = 0
    count = 0
    for num in nums:
        curr_sum += num
        if (curr_sum - goal) in prefix_counts:
            count += prefix_counts[curr_sum - goal]
        prefix_counts[curr_sum] += 1
    return count

# Example
print(num_subarrays_with_sum([1,0,1,0,1], 2))  
print(num_subarrays_with_sum([0,0,0,0,0], 0))  