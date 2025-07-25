def findCelebrity(M):
    n = len(M)
    stack = [i for i in range(n)]
    
    while len(stack) > 1:
        a = stack.pop()
        b = stack.pop()
        if M[a][b] == 1:
            stack.append(b)
        else:
            stack.append(a)

    if not stack:
        return -1

    c = stack.pop()

    for i in range(n):
        if i != c and (M[c][i] == 1 or M[i][c] == 0):
            return -1

    return c

M1 = [
    [0, 1, 1],
    [0, 0, 1],
    [0, 0, 0]
]
print(findCelebrity(M1))

M2 = [
    [0, 1],
    [1, 0]
]
print(findCelebrity(M2))
