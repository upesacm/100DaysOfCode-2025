#Solution Function
def pow_of_2(num):
    count = 0
    while num != 0:
        num &= num - 1
        count += 1
    if count == 1:
        return True
    else:
        return False

#Fixed Input
print(pow_of_2(16))

#Custom Input
num = int(input("Enter the number : "))
print(pow_of_2(num))
