#Solution Function
def sub_1(num):
    n = 1
    while(num & n == 0):
        num ^= n
        n <<= 1
    num ^= n
    return num

#Fixed Input
print(sub_1(4))

#Custom Input
num = int(input("Enter the number : "))
print(sub_1(num))
