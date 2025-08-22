# Implement dynamic sliding window with two pointers to find subarrays matching target sums through efficient window expansion and contraction.
arr = list(map(int, input("Enter the array elements separated by space: ").split()))
target = int(input("Enter the target sum: "))

start = 0
curr_sum = 0
found = False

for end in range(len(arr)):
    curr_sum += arr[end]
    while curr_sum > target and start <= end:
        curr_sum -= arr[start]
        start += 1
    if curr_sum == target:
        print(f"Subarray found from index {start} to {end}")
        found = True
        break

if not found:
    print("No subarray with the given sum found.")
