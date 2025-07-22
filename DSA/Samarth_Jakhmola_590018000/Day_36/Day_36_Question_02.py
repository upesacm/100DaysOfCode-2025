def check_balanced_parentheses(string):
    stack = []

    brackets = {')': '(', '}': '{', ']': '['}

    for i in string:
        if i in '({[':
            stack.append(i)
        elif i in ')}]':
            if not stack or stack[-1] != brackets[i]:
                return "Not Balanced"
            stack.pop()

    return "Balanced" if not stack else "Not Balanced"

try:
    string = input("Enter a string : ")
    print(check_balanced_parentheses(string))
except:
    print("Invalid input. Please try with a valid input.")
