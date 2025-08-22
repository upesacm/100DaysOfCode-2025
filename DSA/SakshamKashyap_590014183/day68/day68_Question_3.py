def largest_sum_after_k_negations(nums, k):
	nums.sort()
	i = 0
	n = len(nums)
	while k > 0 and i < n and nums[i] < 0:
		nums[i] = -nums[i]
		i += 1
		k -= 1
	nums.sort()
	if k % 2 == 1:
		nums[0] = -nums[0]
	return sum(nums)

# Example usage:
if __name__ == "__main__":
	nums1 = [4, 2, 3]
	print(largest_sum_after_k_negations(nums1, 1))  # Output: 5
	nums2 = [3, -1, 0, 2]
	print(largest_sum_after_k_negations(nums2, 3))  # Output: 6
