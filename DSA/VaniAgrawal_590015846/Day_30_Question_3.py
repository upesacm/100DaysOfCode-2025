# Count the number of set bits in an integer using efficient bit manipulation techniques beyond simple iteration.
n = int(input("Enter the number (n): "))

count = 0
while n > 0:
    n = n & (n - 1) 
    count += 1

print(count)
