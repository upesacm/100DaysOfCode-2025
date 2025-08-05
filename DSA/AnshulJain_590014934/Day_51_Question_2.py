arr = list(map(int, input("Enter the array elements separated by spaces: ").split()))
x = int(input("Enter the value of x: "))

n = len(arr)
min_length = n + 1
start = 0
current_sum = 0

for end in range(n):
    current_sum += arr[end]
    while current_sum > x:
        min_length = min(min_length, end - start + 1)
        current_sum -= arr[start]
        start += 1

if min_length == n + 1:
    print("No subarray found with sum greater than", x)
else:
    print("Smallest subarray length with sum greater than", x, "is:", min_length)
#for example:
# Input: [1, 2, 3, 4, 5], x = 8
# Output:2
