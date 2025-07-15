def clear_bit_at_ith(n,i):
    mask = ~(1 << i)
    return n&mask

#example
print(clear_bit_at_ith(7,1))    #output=5