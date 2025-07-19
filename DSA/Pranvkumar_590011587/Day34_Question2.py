# 2. Subtract 1 from an Integer Using Bitwise
def subtract_one(n):
    mask = 1
    while not (n & mask):
        n = n ^ mask      # Flip 0 to 1
        mask <<= 1
    n = n ^ mask          # Flip first 1 to 0
    return n

# --- Test Cases ---
if __name__ == "__main__":
    # Subtract One
    print("\nSubtract 1 using Bitwise:")
    print("Input: 5 -> Output:", subtract_one(5))  
    print("Input: 8 -> Output:", subtract_one(8))  