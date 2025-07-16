#Solution Function
def clear_ith(num, i):
     cleared =  (~(1 << i)) & num
     return cleared

#Fixed Input
print(clear_ith(7, 1))

#Custom Input
num = int(input("Enter the number : "))
i = int(input("Enter the position : "))
print(clear_ith(num, i))
