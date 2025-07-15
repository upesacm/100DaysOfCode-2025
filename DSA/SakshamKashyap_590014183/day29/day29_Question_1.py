# program to find a even-odd number using only bitwise.
def even_odd(n):
    if n & 1 == 0:
        print("Even")
    else:
        print("Odd")

num = int(input("Enter the number: "))
even_odd(num)







