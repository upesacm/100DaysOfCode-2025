def find_next_greater_elements(numbers):
    length = len(numbers)
    result = [-1] * length
    stack = []

    for index in range(length - 1, -1, -1):
        current_number = numbers[index]

        while stack and stack[-1] <= current_number:
            stack.pop()

        if stack:
            result[index] = stack[-1]

        stack.append(current_number)

    return result
