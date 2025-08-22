from functools import cmp_to_key

def compare(a, b):
	if a + b > b + a:
		return -1
	elif a + b < b + a:
		return 1
	else:
		return 0

def largest_number(nums):
	nums_str = list(map(str, nums))
	nums_str.sort(key=cmp_to_key(compare))
	result = ''.join(nums_str)
	return '0' if result[0] == '0' else result

# Example usage:
if __name__ == "__main__":
	print(largest_number([10, 2]))  # Output: "210"
	print(largest_number([3, 30, 34, 5, 9]))  # Output: "9534330"
