#Determine if a number is even or odd using only bitwise operations without arithmetic operators. 
n = int(input("Enter a number: "))

if n & 1:
    print("Odd")
else:
    print("Even")
