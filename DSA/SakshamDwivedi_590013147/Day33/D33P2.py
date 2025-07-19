#Solution Function
def right_turn_off(num):
    num &= num - 1
    return num

#Fixed Input
print(right_turn_off(12))

#Custom Input
num = int(input("Enter the number : "))
print(right_turn_off(num))
