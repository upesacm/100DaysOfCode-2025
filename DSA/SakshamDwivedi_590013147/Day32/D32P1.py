#Solution Function
def swap(num1, num2):
    num1 = num1 ^ num2
    num2 = num1 ^ num2
    num1 = num1 ^ num2
    return num1, num2

#Fixed Input
print("Num 1 : ", swap(1,2)[0], "Num 2 : ", swap(1, 2)[1])

#Custom Input
num1 = int(input("Enter number 1 : "))
num2 = int(input("Enter number 2 : "))
print("Num 1 : ", swap(num1, num2)[0], "Num 2 : ", swap(num1, num2)[1])
