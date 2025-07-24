arr = list(map(int, input("Enter the number:-").split()))#taking input from user
n = len(arr)
res = [-1] * n
stack = []
for i in range(n - 1, -1, -1):
    while stack and stack[-1] <= arr[i]:
        stack.pop()
    if stack:
        res[i] = stack[-1]
    stack.append(arr[i])
print(res)
# for example :
# Input: 4 5 2 10 8
# Output: [5, 10, 10, -1, -1]
