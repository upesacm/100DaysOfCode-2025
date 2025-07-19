def is_binary_palindrome(n):
    left = n.bit_length() - 1  
    right = 0  
    
    while left > right:
        left_bit = (n >> left) & 1
        right_bit = (n >> right) & 1
        
        if left_bit != right_bit:
            return False 
        
        left -= 1
        right += 1
    
    return True
