def three_sum_problem(nums, target = 0):
    nums.sort()
    result = []

    for i in range(len(nums) - 2):
        # Skip duplicate first numbers
        if i > 0 and nums[i] == nums[i - 1]:
            continue

        left, right = i + 1, len(nums) - 1

        while left < right:
            total = nums[i] + nums[left] + nums[right]

            if total < target:
                left += 1
            elif total > target:
                right -= 1
            else:
                result.append([nums[i], nums[left], nums[right]])

                # Skip duplicate 'left' values
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                # Skip duplicate 'right' values
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1

                left += 1
                right -= 1

    return result

try:
    array = list(map(int, input("Enter the elements of the array : ").split()))
    print(three_sum_problem(array))
except:
    print("Invalid input. Please try with a valid input.")
