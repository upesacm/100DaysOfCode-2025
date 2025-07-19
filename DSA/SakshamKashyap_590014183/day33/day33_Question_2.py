def turn_off_right_most_bit(num):
    return num & (num -1)

n = int(input("Enter the number: "))

result = turn_off_right_most_bit(n)
print(result)