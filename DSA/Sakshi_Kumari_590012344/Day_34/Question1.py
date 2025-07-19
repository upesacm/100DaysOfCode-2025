def add_one(n):
    carry = 1 
    
    while carry != 0:
        sum_result = n ^ carry
        
        carry = (n & carry) << 1
  
        n = sum_result
    return n
