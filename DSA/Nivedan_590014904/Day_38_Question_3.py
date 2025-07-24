meth = input("Enter a mathematical experssion: ")
stack = []
for char in meth:
    if char == "(" or char in "+-*/":
        stack.append(char)
    elif char == ")":
        if stack[-1] == "(":
            print("Yes")
            break
        else:
            while stack and stack[-1] in "+-*/":
                stack.pop()
            stack.pop()
else:
    print("No")
