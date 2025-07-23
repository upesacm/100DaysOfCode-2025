def rev(s):
    stack = []
    for c in s:
        stack.append(c)
    revstr = "" 
    while stack:
        revstr += stack.pop()
    return(revstr)
s = input("Enter a String: ")
print(rev(s))
