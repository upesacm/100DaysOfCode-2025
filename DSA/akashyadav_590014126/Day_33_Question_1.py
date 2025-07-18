def check_op_sign(a,b):
    if (a^b)<0:
        return True
    else:
        return False
    
#example
print(check_op_sign(4,-5))