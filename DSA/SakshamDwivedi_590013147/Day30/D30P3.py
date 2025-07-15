#This uses Kernighan's algorithm
def count_1_bits(num):
    count = 0
    while num != 0:
        num = num & (num - 1)
        count += 1
    return count

#Python Specific Gigachad Solution
def py_bit_count(num):
    return num.bit_count()


#Fixed Input
print(count_1_bits(7))
print(py_bit_count(7))

#Custom Input
num = int(input("Enter the number : "))
print(count_1_bits(num))
print(py_bit_count(num))
