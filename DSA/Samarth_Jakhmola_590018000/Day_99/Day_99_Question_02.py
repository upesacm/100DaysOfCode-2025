def maximum_sliding_window(array, k):
    result = []
    n = len(array)

    for i in range(n - k + 1):
        stack = []  # simulate window with stack
        # push k elements of current window into stack
        for j in range(i , i + k):
            stack.append(array[j])
        # max of stack = max(stack)
        result.append(max(stack))

    return result

array = list(map(int, input("Enter the elements of the array separated by spaces : ").split()))
k = int(input("Enter the value of k : "))
print(maximum_sliding_window(array, k))
