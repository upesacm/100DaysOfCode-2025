def findCelebrity(M):
    n = len(M)
    stack = list(range(n))
    # Eliminate non-celebrities
    while len(stack) > 1:
        a = stack.pop()
        b = stack.pop()
        if M[a][b]:
            stack.append(b)
        else:
            stack.append(a)
    if not stack:
        return -1
    candidate = stack.pop()
    # Verify candidate
    for i in range(n):
        if i != candidate and (M[candidate][i] == 1 or M[i][candidate] == 0):
            return -1
    return candidate

# Examples:
print(findCelebrity([[0, 1, 1], [0, 0, 1], [0, 0, 0]])) 
print(findCelebrity([[0, 1], [1, 0]]))                 
