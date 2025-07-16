def count_bit(n):
    count = 0
    while n:
        n &= (n-1)
        count+=1
    return count

num = int(input("Enter the number: "))
result = count_bit(num)
print(f"the number of set bits in an integer is: {result}")
