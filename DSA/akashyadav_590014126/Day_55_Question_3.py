def num_subarrays_with_sum(nums, goal):
    from collections import defaultdict

    prefix_sum_count = defaultdict(int)
    prefix_sum_count[0] = 1  
    curr_sum = 0
    count = 0

    for num in nums:
        curr_sum += num
        count += prefix_sum_count[curr_sum - goal]
        prefix_sum_count[curr_sum] += 1

    return count
