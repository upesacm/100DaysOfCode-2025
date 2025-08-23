def maximum_sum_after_K_negations(nums, k):
    nums.sort()

    for i in range(len(nums)):
        if nums[i] < 0 and k > 0:
            nums[i] = -nums[i]
            k -= 1

    nums.sort()  # Sort again to bring the smallest element at the front.

    if k % 2 == 1:
        nums[0] = -nums[0]

    return sum(nums)

try:
    nums = list(map(int, input("Enter the numbers of the array, separated by spaces : ").split()))
    k = int(input("Enter the value of k : "))
    print(maximum_sum_after_K_negations(nums, k))
except:
    print("Invalid input. Please try with a valid input.")
