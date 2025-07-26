n = int(input("Enter number of people: "))
matrix = []
for _ in range(n):
    matrix.append(list(map(int, input().split())))
stack = []
for i in range(n):
    stack.append(i)
while len(stack) > 1:
    a = stack.pop()
    b = stack.pop()
    if matrix[a][b] == 1:
        stack.append(b)
    else:
        stack.append(a)
if not stack:
    print(-1)
else:
    candidate = stack.pop()
    for i in range(n):
        if i != candidate:
            if matrix[candidate][i] == 1 or matrix[i][candidate] == 0:
                print(-1)
                break
    else:
        print(candidate)
#for example:
# Input: node count = 3
#        matrix =0 1 1
#                0 0 1
#                0 0 0
# Output: 2