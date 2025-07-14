def even_or_odd_bit_manipulation(n):
    if n < 0:
        print("Invalid input.")
    else:
        if n & 1:
            print("Odd")
        else:
            print("Even")

try:
    n = int(input("Enter an integer : "))
    even_or_odd_bit_manipulation(n)
except:
    print("Invalid input. Please try with a valid input.")
