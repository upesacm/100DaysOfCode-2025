def stack_max_window(arr, k):
    if not arr or k <= 0:
        return []

    result = []
    stack = []

    for i in range(len(arr)):
        stack.append(arr[i])

        if len(stack) == k:
            max_val = stack[0] 
            for val in stack:
                if val > max_val:
                    max_val = val
            result.append(max_val)

            stack.pop(0)  

    return result

#The inefficiency in stack operations is the use of pop(0), which is O(n) because it shifts elements.
#2.stack.pop(0) is not optimal because popping from the front of a list requires shifting all other elements, causing O(n) time complexity.
#3.The correct approach is to use a deque, which allows O(1) time popping from both ends,
#and maintain a monotonic deque that keeps the elements in decreasing order to efficiently get max in O(n).
