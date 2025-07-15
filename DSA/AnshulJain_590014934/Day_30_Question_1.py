n = int(input("Enter the number:"))#Takin input from the usesr
i = int(input("Enter the bit position to clear (0-indexed):"))
mask = ~(1 << i)
result = n & mask
print(result)
#for example 
# if n = 7  and i = 1, the output will be 5 
