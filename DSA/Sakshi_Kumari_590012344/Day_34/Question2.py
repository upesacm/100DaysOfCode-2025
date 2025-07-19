def subtract_one(n):
    borrow = 1  
    while borrow != 0:
        result = n ^ borrow
        borrow = (~n & borrow) << 1 
        n = result 
    return n
