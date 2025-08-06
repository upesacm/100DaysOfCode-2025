#Implement dynamic sliding window with threshold tracking to find the smallest subarray exceeding target sums through efficient window management.
arr_input = input("Enter the array elements separated by space: ")
arr = list(map(int, arr_input.strip().split()))
x = int(input("Enter x: "))

n = len(arr)
min_len = n + 1
start = 0
curr_sum = 0

for end in range(n):
    curr_sum += arr[end]

    while curr_sum > x:
        min_len = min(min_len, end - start + 1)
        curr_sum -= arr[start]
        start += 1

if min_len == n + 1:
    print("Output:")
    print(0)
else:
    print("Output:")
    print(min_len)
