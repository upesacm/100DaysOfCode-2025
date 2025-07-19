# 1. Add 1 to an Integer Using Bitwise
def add_one(n):
    mask = 1
    while n & mask:
        n = n ^ mask      # Flip 1 to 0
        mask <<= 1        # Move to next bit
    n = n ^ mask          # Flip first 0 to 1
    return n

# --- Test Cases ---
if __name__ == "__main__":
    # Add One
    print("Add 1 using Bitwise:")
    print("Input: 4 -> Output:", add_one(4))    
    print("Input: 7 -> Output:", add_one(7)) 
