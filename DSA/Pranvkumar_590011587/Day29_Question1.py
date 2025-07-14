def check_parity(n):
    if n & 1:
        return "Odd"
    else:
        return "Even"

# Example usage
print(check_parity(4))  
print(check_parity(7))  
