def Opposite_sign(a,b):
    return (a ^ b) < 0

num1 = int(input("Enter the number 1: "))
num2 = int(input("Enter the number 2: "))

result = Opposite_sign(num1,num2)

print(result)

