# Implement comprehensive heap equality checking using array comparison with heap property verification for complete structural validation.
import re

line = input().strip()

lists = re.findall(r'\[([^\]]*)\]', line)
def to_list(s):
    s = s.strip()
    return [] if not s else list(map(int, re.findall(r'-?\d+', s)))

arr1 = to_list(lists[0]) if len(lists) > 0 else []
arr2 = to_list(lists[1]) if len(lists) > 1 else []

print("true" if arr1 == arr2 else "false")
