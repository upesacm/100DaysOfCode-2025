def add_one(x):
    carry=1
    while x & carry:
        x=x^carry
        carry <<= 1
    x=x^carry
    return x 

#example
print(add_one(9))