def change_ith(num, i):
    num = num ^ (1 << i);
    return num

#Fixed Input
print(change_ith(5, 1))

#Custom Input
num = int(input("Enter the number : "))
i = int(input("Enter i : "))
print(change_ith(num, i))
