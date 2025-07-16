n = int(input("Enter the value of n: "))
count = 0
while n != 0:
    count+= n&1
    n = n>>1
print(count)
