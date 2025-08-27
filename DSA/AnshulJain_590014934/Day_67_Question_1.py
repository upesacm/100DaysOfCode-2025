from functools import cmp_to_key

def largest_number(nums):
    def compare(a, b):
        return -1 if a+b > b+a else 1 if a+b < b+a else 0
    nums = list(map(str, nums))
    nums.sort(key=cmp_to_key(compare))
    result = ''.join(nums)
    return '0' if result[0] == '0' else result

nums = list(map(int, input("Enter numbers separated by space: ").split()))
print(largest_number(nums))
