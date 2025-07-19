# Check if Two Numbers Have Opposite Signs
a = int(input("Enter first number a: "))
b = int(input("Enter second number b: "))

if (a ^ b) < 0:
    print("Output:", True)
else:
    print("Output:", False)
