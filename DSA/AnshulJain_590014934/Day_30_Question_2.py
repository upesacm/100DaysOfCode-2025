n = int(input("Enter the number:"))  # Taking input from the user
i = int(input("Enter the bit position to toggle (0-indexed):"))
mask = 1 << i
result = n ^ mask
print(result) 
#for example
#input: n=10 and i=1 , so the output will be 8
