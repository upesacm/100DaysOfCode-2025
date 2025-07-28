def remove_adjacent_duplicates(s):
    while True:
        stack = []
        i = 0
        changed = False
        while i < len(s):
            if stack and stack[-1] == s[i]:
           
                while i + 1 < len(s) and s[i] == s[i + 1]:
                    i += 1

                stack.pop()
                changed = True
            else:
                stack.append(s[i])
            i += 1

        reduced = ''.join(stack)
        if not changed:
            return reduced
        else:
            s = reduced
