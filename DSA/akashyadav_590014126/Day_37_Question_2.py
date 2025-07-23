def evaluate_postfix(expr):
    stack=[]

    for ch in expr:
        if ch.isdigit():
            stack.append(int(ch))
        else:
            b=stack.pop()
            a=stack.pop()
        
        if ch=='+':
            stack.append(a+b)

        if ch=='-':
            stack.append(a-b)

        if ch=='*':
            stack.append(a*b)

        if ch=='/':
            stack.append(a/b)
    
    return stack[-1]

#example
print(evaluate_postfix("78-"))