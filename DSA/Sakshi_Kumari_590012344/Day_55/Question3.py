def num_subarrays_with_sum(arr, goal):
    prefix_sum_count = {0: 1}
    cumulative_sum = 0
    count = 0

    for num in arr:
        cumulative_sum += num

        if cumulative_sum - goal in prefix_sum_count:
            count += prefix_sum_count[cumulative_sum - goal]

        if cumulative_sum in prefix_sum_count:
            prefix_sum_count[cumulative_sum] += 1
        else:
            prefix_sum_count[cumulative_sum] = 1

    return count
