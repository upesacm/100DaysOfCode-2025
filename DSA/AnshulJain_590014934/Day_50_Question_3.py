arr = list(map(int, input("Enter the array:-").split()))
target = int(input("Enter the target sum: "))
start = 0
current_sum = 0
found = False
for end in range(len(arr)):
    current_sum += arr[end]
    while current_sum > target and start < end:
        current_sum -= arr[start]
        start += 1
    if current_sum == target:
        print(f"Subarray found from index {start} to {end}")
        found = True
        break
if not found:
    print("No subarray found")
#for example:
# Input: Enter the array:- 1 2 3 4 5
#        Enter the target sum: 9
# Output: Subarray found from index 0 to 3  
