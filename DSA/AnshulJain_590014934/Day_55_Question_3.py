nums = list(map(int, input("Enter the arr").split()))
goal = int(input("Enter the goal: "))
prefix_sum = 0
count_map = {0: 1}
res = 0
for num in nums:
    prefix_sum += num
    if prefix_sum - goal in count_map:
        res += count_map[prefix_sum - goal]
    count_map[prefix_sum] = count_map.get(prefix_sum, 0) + 1
print(res)
#for example:
# Input: nums = [1, 1, 1], goal = 2
# Output: 2