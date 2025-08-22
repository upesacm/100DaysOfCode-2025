arr = list(map(int, input("Enter The array:-").split()))
k = int(input("Enter the value of k: "))
n = len(arr)
if n < k:
    print("Invalid")
else:
    window_sum = sum(arr[:k])
    max_sum = window_sum
    for i in range(k, n):
        window_sum += arr[i] - arr[i - k]
        max_sum = max(max_sum, window_sum)
    print(max_sum)
#for example:
# Input: Enter The array:- 1 2 3 4 5 6
#        Enter the value of k: 3
# Output: 15
