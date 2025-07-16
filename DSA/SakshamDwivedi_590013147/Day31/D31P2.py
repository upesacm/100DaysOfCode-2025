#Solution Function
def mult_by_2(num):
    num = num << 1
    return num

#Fixed Input
print(mult_by_2(4))

#Custom Input
num = int(input("Enter the number : "))
print(mult_by_2(num))
