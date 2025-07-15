#Solution Function
def toggle(num, i):
    toggled = (1 << i) ^ num
    return toggled

#Fixed Input
print(toggle(10, 1))

#Custom Input
num = int(input("Enter the number : "))
i = int(input("Enter the position : "))
print(toggle(num, i))
