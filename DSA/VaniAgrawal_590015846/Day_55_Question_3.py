#Implement prefix sum frequency counting to enumerate all binary subarrays meeting goal sum requirements through efficient pattern analysis.
nums = list(map(int, input("Enter binary array elements separated by space: ").split()))
goal = int(input("Enter goal sum: "))

count_map = {0: 1}
prefix_sum = 0
count = 0

for num in nums:
    prefix_sum += num
    if (prefix_sum - goal) in count_map:
        count += count_map[prefix_sum - goal]
    count_map[prefix_sum] = count_map.get(prefix_sum, 0) + 1

print("Number of subarrays:", count)
