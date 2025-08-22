from functools import cmp_to_key

def largest_number(nums):
    def cmp(a,b):
        return -1 if a+b>b+a else 1 if a+b<b+a else 0
    nums = list(map(str,nums))
    nums.sort(key=cmp_to_key(cmp))
    res = ''.join(nums)
    return '0' if res[0]=='0' else res

print(largest_number([10,2]))
print(largest_number([3,30,34,5,9]))
