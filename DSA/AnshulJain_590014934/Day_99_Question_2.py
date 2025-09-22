arr = list(map(int, input("Enter array elements separated by space: ").split()))
k = int(input("Enter window size: "))
stack, result = [], []
for i in range(len(arr)):
    while stack and arr[stack[-1]] <= arr[i]:
        stack.pop()
    stack.append(i)
    if stack[0] <= i - k:
        stack.pop(0)
    if i >= k - 1:
        result.append(arr[stack[0]])
print(result)
