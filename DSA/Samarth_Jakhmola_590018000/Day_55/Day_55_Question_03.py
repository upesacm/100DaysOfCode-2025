def binary_subarray_with_sum(nums, goal):
    prefix_sum_count = {0 : 1}  # Stores frequency of prefix sums
    curr_sum = 0
    count = 0

    for num in nums:
        curr_sum += num

        # Check if we have seen a prefix sum that would give 'goal'
        if (curr_sum - goal) in prefix_sum_count:
            count += prefix_sum_count[curr_sum - goal]

        # Store the current prefix sum in the dictionary
        prefix_sum_count[curr_sum] = prefix_sum_count.get(curr_sum, 0) + 1

    return count

try:
    nums = list(map(int, input("Enter the elements of the array : ").split()))
    goal = int(input("Enter the value of goal : "))
    print(binary_subarray_with_sum(nums, goal))
except:
    print("Invalid input. Please try with a valid input.")
