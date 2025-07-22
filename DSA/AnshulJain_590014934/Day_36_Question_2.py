stack = []
brackets = {')': '(', '}': '{', ']': '['}
s = input("Enter a string with brackets: ")  # taking input from the user
balanced = True
for char in s:
    if char in '({[':
        stack.append(char)
    elif char in ')}]':
        if not stack or stack.pop() != brackets[char]:
            balanced = False
            break
if stack:
    balanced = False
print("Balanced" if balanced else "Not Balanced")
#for example:-
#input:- {[()]}
#output:- Balanced
