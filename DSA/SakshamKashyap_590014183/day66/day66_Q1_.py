
def find_min_platforms(arr, dep):
	n = len(arr)
	arr.sort()
	dep.sort()
	platform_needed = 1
	max_platforms = 1
	i, j = 1, 0
	while i < n and j < n:
		if arr[i] <= dep[j]:
			platform_needed += 1
			max_platforms = max(max_platforms, platform_needed)
			i += 1
		else:
			platform_needed -= 1
			j += 1
	return max_platforms

# Example usage:
if __name__ == "__main__":
	arr = [900, 940, 950, 1100, 1500, 1800]
	dep = [910, 1200, 1120, 1130, 1900, 2000]
	print(find_min_platforms(arr, dep))  # Output: 3
	arr2 = [100, 200, 300]
	dep2 = [150, 250, 350]
	print(find_min_platforms(arr2, dep2))  # Output: 1
