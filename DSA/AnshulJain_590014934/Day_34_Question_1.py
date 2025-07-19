n = int(input("Enter a number: "))#Taking input from user
c = 1
while c != 0:
    s = n ^ c
    c = (n & c) << 1
    n = s
print(n)
#for example 
# input: 5
# output: 6