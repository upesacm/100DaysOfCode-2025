def remove_adjacent_duplicates(s):
    while True:
        stack=[]
        i=0
        changed=False

        while i<len(s):
            if stack and stack[-1] == s[i]:
                changed=True
                stack.pop()
            else:
                stack.append(s[i])
            i += 1

        new_s = ' '.join(stack)
        if not changed:
            return new_s
        s=new_s

#example
print(remove_adjacent_duplicates("abbaca"))