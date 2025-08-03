def subtract_one(x):
    borrow=1
    while x & borrow == 0:
        x=x^borrow
        borrow <<= 1
    x=x^borrow
    return x

#example
print(subtract_one(9))