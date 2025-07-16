#Solution Function
def div_by_2(num):
    num = num >> 1
    return num

#Fixed Input
print(div_by_2(8))

#Custom Input
num = int(input("Enter the number : "))
print(div_by_2(num))
