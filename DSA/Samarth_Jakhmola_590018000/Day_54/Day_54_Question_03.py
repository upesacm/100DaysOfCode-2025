def subarray_with_product_less_than_K(nums, k):
    if k <= 1:  # No subarray can have product < 1
        return 0
    
    product = 1
    left = 0
    count = 0

    for right in range(len(nums)):
        product *= nums[right]

        # Shrink the window until product < k
        while product >= k:
            product //= nums[left]  # integer division to avoid float issues
            left += 1

        # All subarrays ending at right are valid
        count += (right - left + 1)

    return count

try:
    nums = list(map(int, input("Enter the elements of the array : ").split()))
    k = int(input("Enter the value of k : "))
    print(subarray_with_product_less_than_K(nums, k))
except:
    print("Invalid input. Please try with a valid input.")
