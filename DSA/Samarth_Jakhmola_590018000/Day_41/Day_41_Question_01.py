def remove_adjacent_duplicates(string):
    stack = []

    for char in string:
        if stack and stack[-1] == char:
            stack.pop()
        else:
            stack.append(char)

    return ''.join(stack)

try:
    string = input("Enter the string : ")
    print(f"\"{remove_adjacent_duplicates(string)}\"")
except:
    print("Invalid input. Please try with a valid input.")
