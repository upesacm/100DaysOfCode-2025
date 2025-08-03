def count_set_bits(n):
    count = 0
    
    # Using Brian Kernighan's algorithm
    while n:
        n &= (n - 1)  # This will keep clearing the rightmost set bit, id there's any, thus counting the number of times 1 occurs.
        count += 1
    return count

try:
    n = int(input("Enter an integer : ")) 
    print(count_set_bits(n))
except:
    print("Invalid input. Please try with a valid input.")
