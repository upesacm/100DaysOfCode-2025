Your task: Determine if a number is even or odd using only bitwise operations without 
arithmetic operators.

def check_even_odd(n):
    if not isinstance(n, int):
        print("Error: Input must be an integer.")
        return
    if n & 1:
        print(f"{n} is odd.")
    else:
        print(f"{n} is even.")
