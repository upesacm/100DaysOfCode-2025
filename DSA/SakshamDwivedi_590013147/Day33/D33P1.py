#Solution Function
def opposite_sign(num1, num2):
    num1 = (num1 & 0xFFFFFFFF)>> 31
    '''The reason that we use (num & 0xFFFFFFFF) >> 31 instead of (num >> 31) & 1 like C
    is because Python doesn't use fixed length integers. So num & 0xFFFFFFFF converts the
    number to it's 32 bit 2's complement format if it's negative.'''
    num2 = (num2 & 0xFFFFFFFF) >> 31
    if num1 ^ num2:
        return True
    else:
        return False

#Fixed Input
print(opposite_sign(2, -3))

#Custom Input
num1 = int(input("Enter number 1 : "))
num2 = int(input("Enter number 2 : "))
print(opposite_sign(num1, num2))
