def find_celebrity(matrix, n):
    stack = [i for i in range(n)]
    while len(stack) > 1:
        A = stack.pop()
        B = stack.pop()

        if matrix[A][B] == 1:
            stack.append(B)
        else:
            stack.append(A)

        if not stack:
            return -1
        
        candidate = stack.pop()

        for i in range(n):
            if i != candidate:
                if matrix[candidate][i] == 1 or matrix[i][candidate] == 0:
                    return -1
                
        return candidate
    
try:
    n = int(input("Enter the number of people in the party : "))
    print(f"Enter the elements of the {n} x {n} matrix row wise separated by spaces : ")
    matrix = []
    for i in range(n):
        row = list(map(int, input().split()))
        matrix.append(row)

    result = find_celebrity(matrix, n)
    print(result if result != -1 else -1)
except:
    print("Invalid input. Please try with a valid input.")
