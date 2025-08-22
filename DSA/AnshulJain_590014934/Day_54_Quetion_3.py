nums = list(map(int, input("Enter numbers separated by space: ").split()))
k = int(input("Enter the value of k: "))
if k <= 1:
    print(0)
else:
    prod = 1
    left = 0
    count = 0
    for right in range(len(nums)):
        prod *= nums[right]
        while prod >= k:
            prod //= nums[left]
            left += 1
        count += right - left + 1
    print(count)
