def num_sum(nums, goal):
    prefix_sum = 0
    freq = {0: 1}
    count = 0

    for num in nums:
        prefix_sum += num
        if prefix_sum - goal in freq:
            count += freq[prefix_sum - goal]
        if prefix_sum in freq:
            freq[prefix_sum] += 1
        else:
            freq[prefix_sum] = 1

    return count


#Fixed Input
nums = [1, 0, 1, 0, 1]
goal = 2
print(num_sum(nums, goal))
