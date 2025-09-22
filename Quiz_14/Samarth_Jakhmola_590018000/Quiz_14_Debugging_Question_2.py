#   For test case 1 : It will likely IndexError or wrong result because it misuses wrong indices. 
#   
#   For test case 2 : It returns IndexError or wrong result here as well, often 10, due to wrong indexing.
# 
#   
#   1.  The code uses weights[i] and values[i]. But dp[i] corresponds to the ith item (1-based in dp), while arrays weights/values are
#       0-based. Correct access should be weights[i - 1], values[i - 1].
# 
# 
#   2.  When i = n (last iteration), accessing weights[i] or values[i] tries to fetch an element beyond the array length -> IndexError. In
#       some cases, if error doesn't occur, it uses wrong item indices.
# 
# 
#   3.  It should be :
#           if weights[i - 1] <= w:
#               include_value = dp[i - 1][w - weights[i - 1]] + values[i - 1]
