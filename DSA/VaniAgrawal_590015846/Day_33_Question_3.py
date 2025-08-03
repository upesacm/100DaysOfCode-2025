# Isolate the Rightmost Set Bit
n = int(input("Enter a number: "))

result = n & -n
print("Output:", result)
