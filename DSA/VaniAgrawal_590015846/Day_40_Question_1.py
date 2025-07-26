# Use stack-based candidate elimination to efficiently identify the celebrity by systematically reducing potential candidates through relationship queries. 
n = int(input("Enter number of people: "))

M = []
print("Enter the matrix row-wise:")
for i in range(n):
    row = list(map(int, input().split()))
    M.append(row)

stack = []
for i in range(n):
    stack.append(i)

while len(stack) > 1:
    a = stack.pop()
    b = stack.pop()

    if M[a][b] == 1:
        stack.append(b)
    else:
        stack.append(a)

if len(stack) == 0:
    print(-1)
else:
    c = stack.pop()
    is_celeb = True

    for i in range(n):
        if i != c:
            if M[c][i] != 0 or M[i][c] != 1:
                is_celeb = False
                break

    if is_celeb:
        print(c)
    else:
        print(-1)
