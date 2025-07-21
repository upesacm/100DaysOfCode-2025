#Solution Function
def right_most_bit(num):
   num &= -num
   return num

#Fixed Input
print(right_most_bit(10))

#Custom Input
num = int(input("Enter the number : "))
print(right_most_bit(num))
