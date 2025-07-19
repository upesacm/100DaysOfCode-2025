n = int(input("Enter any number: "))
m = 1
while (n & m):
    n = n ^ m
    m <<= 1
n = n ^ m
print(n)