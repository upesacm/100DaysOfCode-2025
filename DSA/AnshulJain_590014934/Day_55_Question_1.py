arr = list(map(int, input("Enter the arr:-").split()))
k = int(input("Enter the k:-"))
prefix_sum = 0
sum_map = {}
max_len = 0
for i in range(len(arr)):
    prefix_sum += arr[i]
    if prefix_sum == k:
        max_len = i + 1
    if prefix_sum - k in sum_map:
        max_len = max(max_len, i - sum_map[prefix_sum - k])
    if prefix_sum not in sum_map:
        sum_map[prefix_sum] = i
print(max_len)
#for example:
# Input: arr = [1, 2, 3, 4, 5], k = 9
# Output: 3