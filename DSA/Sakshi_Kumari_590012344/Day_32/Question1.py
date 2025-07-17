def swap_numbers(a, b):
    print(f"Before swapping: a = {a}, b = {b}")
    
    if a == b:
        print("Both numbers are the same. No swap needed.")
        return a, b

    a = a ^ b
    b = a ^ b
    a = a ^ b

    print(f"After swapping: a = {a}, b = {b}")
    return a, b

a = int(input("Enter first number (a): "))
b = int(input("Enter second number (b): "))
swap_numbers(a, b)
