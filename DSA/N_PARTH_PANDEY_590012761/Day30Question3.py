n = int(input("Enter any number: "))
count = 0
while n > 0:
    n &= n - 1
    count += 1
print(count)