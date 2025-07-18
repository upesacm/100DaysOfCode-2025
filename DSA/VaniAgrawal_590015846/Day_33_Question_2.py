#turn Off the Rightmost Set 
n = int(input("Enter a number: "))

result = n & (n - 1)
print("Output:", result)
