def find_celebrity(M, n):
    stack = [i for i in range(n)]

    while len(stack) > 1:
        A = stack.pop()
        B = stack.pop()

        if M[A][B] == 1:
            stack.append(B)
        else:
            stack.append(A)

    if not stack:
        return -1

    candidate = stack.pop()

    for i in range(n):
        if M[candidate][i] == 1:
            return -1

    for i in range(n):
        if i != candidate and M[i][candidate] == 0:
            return -1

    return candidate
