def isolate_rightmost(a):
    return (a & -a)

#example
print(isolate_rightmost(7))