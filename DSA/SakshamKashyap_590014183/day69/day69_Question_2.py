def can_partition(nums):
	total = sum(nums)
	if total % 2 != 0:
		return False
	target = total // 2
	n = len(nums)
	dp = [False] * (target + 1)
	dp[0] = True
	for num in nums:
		for i in range(target, num - 1, -1):
			dp[i] = dp[i] or dp[i - num]
	return dp[target]

# Example usage:
if __name__ == "__main__":
	print(can_partition([1, 2, 3, 5]))  # Output: False
	print(can_partition([1, 5, 11, 5]))  # Output: True
