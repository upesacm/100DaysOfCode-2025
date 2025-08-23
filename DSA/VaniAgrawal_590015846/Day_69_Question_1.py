# Rearrange Array to Form Palindrome
from collections import Counter
s = input()
freq = Counter(s)
odd_count = sum(1 for v in freq.values() if v % 2 != 0)
print("Yes" if odd_count <= 1 else "No")
