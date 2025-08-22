fruits = list(map(int, input("Enter fruit types separated by space: ").split()))
from collections import defaultdict
count = defaultdict(int)
left = 0
max_len = 0
for right in range(len(fruits)):
    count[fruits[right]] += 1
    while len(count) > 2:
        count[fruits[left]] -= 1
        if count[fruits[left]] == 0:
            del count[fruits[left]]
        left += 1
    max_len = max(max_len, right - left + 1)
print("Maximum number of fruits in two baskets:", max_len)
#for example 
# Input: 1 2 1 2 3
# Output: Maximum number of fruits in two baskets: 4