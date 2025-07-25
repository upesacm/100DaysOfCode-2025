def find_celebrity(matrix):
    """
    Finds the celebrity in a party, if one exists.
    A celebrity is known by everyone but knows no one.
    """
    n = len(matrix)
    stack = list(range(n))

    # 1. Candidate Elimination
    # Reduce the candidates down to one potential celebrity.
    while len(stack) > 1:
        a = stack.pop()
        b = stack.pop()

        # If a knows b, then a cannot be a celebrity.
        # So, b might be the celebrity. Push b back.
        if matrix[a][b] == 1:
            stack.append(b)
        # If a does not know b, then b cannot be a celebrity.
        # So, a might be the celebrity. Push a back.
        else:
            stack.append(a)

    # If the stack is empty, there are no candidates left.
    if not stack:
        return -1

    # 2. Candidate Verification
    # The last person in the stack is our potential celebrity.
    candidate = stack[0]

    for i in range(n):
        # Skip checking the candidate against themselves.
        if i == candidate:
            continue
        
        # Check if the candidate knows anyone (row check)
        # or if someone doesn't know the candidate (column check).
        if matrix[candidate][i] == 1 or matrix[i][candidate] == 0:
            return -1 # This candidate is not a celebrity.

    # If the candidate passes all checks, they are the celebrity.
    return candidate

# --- Test cases ---

# Example 1: Person 2 is the celebrity
# 0 knows 1 and 2
# 1 knows 2
# 2 knows no one
matrix1 = [
    [0, 1, 1],
    [0, 0, 1],
    [0, 0, 0]
]
print(f"Celebrity is person: {find_celebrity(matrix1)}")


# Example 2: No celebrity
matrix2 = [
    [0, 1],
    [1, 0]
]
print(f"Celebrity is person: {find_celebrity(matrix2)}")


# Example 3: Person 1 is the celebrity
matrix3 = [
    [0, 1, 0],
    [0, 0, 0],
    [0, 1, 0]
]
print(f"Celebrity is person: {find_celebrity(matrix3)}")
