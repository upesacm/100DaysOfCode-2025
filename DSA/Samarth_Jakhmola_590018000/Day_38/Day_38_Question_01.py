def next_greater_element(array):
    result = [-1] * len(array)   # Setting all the elements to -1 as default
    stack = []

    for i in range(len(array)):
        while stack and array[i] > array[stack[-1]]:
            index = stack.pop()
            result[index] = array[i]
        stack.append(i)

    return result

try:
    stack = list(map(int, input("Enter the elements of the stack separated by spaces : ").split()))
    print(next_greater_element(stack))
except:
    print("Invalid input. Please try with a valid input.")
