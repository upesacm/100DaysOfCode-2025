from functools import cmp_to_key

def compare(a, b):
    return (1 if a + b < b + a else -1)

def largest_number(nums):
    str_nums = list(map(str, nums))
    str_nums.sort(key=cmp_to_key(compare))
    return '0' if str_nums[0] == '0' else ''.join(str_nums)

# Test cases
print(largest_number([10, 2]))           # "210"
print(largest_number([3, 30, 34, 5, 9])) # "9534330"
