#Implement a monotonic stack solution to find the next greater element for each array position in linear time complexity. 
arr = list(map(int, input("Enter the array elements separated by space: ").split()))
n = len(arr)
res = [-1] * n
stack = []

for i in range(n - 1, -1, -1):
    while stack and stack[-1] <= arr[i]:
        stack.pop()
    if stack:
        res[i] = stack[-1]
    stack.append(arr[i])

print("Output:")
print(res)
