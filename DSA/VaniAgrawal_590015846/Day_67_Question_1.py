# Largest Number from Array
from functools import cmp_to_key
arr = list(map(str, input().split()))
def compare(a, b):
    return -1 if a+b > b+a else 1
arr.sort(key=cmp_to_key(compare))
print("".join(arr).lstrip("0") or "0")
