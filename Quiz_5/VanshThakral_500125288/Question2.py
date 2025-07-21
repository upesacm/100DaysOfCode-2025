
#task1 if (n & (n - 1)) == 0:   this line gives wrong result for negative numbers
#Correct code:

def is_power_of_two(n):
    if n <= 0:        
        return False

    return (n & (n - 1)) == 0
