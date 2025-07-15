n = int(input("Enter the number:"))  # Taking input from the user
count = 0
while n:
    n &= n - 1
    count += 1
print(count)
#for example
# input : n=7 , so the output will be 3
