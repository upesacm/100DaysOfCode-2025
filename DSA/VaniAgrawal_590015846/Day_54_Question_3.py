#Implement sliding window with product constraint tracking to count all valid subarrays meeting multiplicative threshold requirements efficiently.

nums = list(map(int, input("Enter numbers separated by spaces: ").split()))
k = int(input("Enter k: "))

if k <= 1:
    print("Output: 0")
else:
    product = 1
    left = 0
    count = 0
    for right in range(len(nums)):
        product *= nums[right]
        while product >= k:
            product /= nums[left]
            left += 1
        count += right - left + 1

    print("Output:", count)
