'''

1. The bug is that the code doesn't work correctly for negative numbers.

2. Negative numbers can satisfy ' (n & (n-1)) == 0 ' but they are not valid powers of 2 in mathematical terms. Therefore, we can add a 
   check for negative numbers like - 

   if n <= 0:
    return False

   This can be added just at the beginning of the function itself.

'''
