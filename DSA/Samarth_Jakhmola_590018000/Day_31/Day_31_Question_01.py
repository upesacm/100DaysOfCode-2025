def check_power_of_two(n):
    if n < 0:
        exit()
    else:
        count = 0
    
        # Using Brian Kernighan's algorithm to count the number of ones in the number.
        while n:
            n &= (n - 1)
            count += 1
        return count

try:
    n = int(input("Enter a positive integer : "))
    print("Yes" if check_power_of_two(n) == 1 else "No")
except:
    print("Invalid input. Please try with a valid input.")
