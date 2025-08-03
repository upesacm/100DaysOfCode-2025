n = int(input("Enter a number: "))  # Taking input from user
m = 1
while not (n & m):
    n = n ^ m
    m = m << 1
n = n ^ m
print(n)
# For example
# input: 5
# output: 4
