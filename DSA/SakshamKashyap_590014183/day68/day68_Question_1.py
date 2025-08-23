def min_jumps(arr):
	n = len(arr)
	if n <= 1:
		return 0
	if arr[0] == 0:
		return -1
	jumps = 1
	max_reach = arr[0]
	step = arr[0]
	for i in range(1, n):
		if i == n - 1:
			return jumps
		max_reach = max(max_reach, i + arr[i])
		step -= 1
		if step == 0:
			jumps += 1
			if i >= max_reach:
				return -1
			step = max_reach - i
	return -1

# Example usage:
if __name__ == "__main__":
	arr1 = [2, 3, 1, 1, 4]
	print(min_jumps(arr1))  # Output: 2
	arr2 = [1, 1, 1, 1]
	print(min_jumps(arr2))  # Output: 3
