def Next_Greater_Elements(arr):
    n = len(arr)
    result = [-1] * n
    stack = []
    for i in range(n):
        while stack and arr[i] > arr[stack[-1]]:
            popped_index = stack.pop()
            result[popped_index] = arr [i]
        stack.append(i)
    return result
#test cases  
print(Next_Greater_Elements([4,5,2,25]))
print(Next_Greater_Elements([13,7,6,12]))