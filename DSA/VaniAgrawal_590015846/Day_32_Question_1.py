# Swap Two Numbers Without Temporary Variable 
a = int(input("Enter value of a: "))
b = int(input("Enter value of b: "))

a = a ^ b
b = a ^ b
a = a ^ b

print("After swap:")
print("a =", a)
print("b =", b)
