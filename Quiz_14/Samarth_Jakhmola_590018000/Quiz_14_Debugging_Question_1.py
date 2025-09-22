#   For test case 1 :  It is likely to return 0 or smaller.async
# 
#   For test case 2 : It is likely to return 2.
# 
#   For test case 3 : It will return 0.
#  
#   
#   1.  The code incorrectly uses text1[i] and text2[j]. Since dp indices start from 1 but strings start from 0, this causes an off-by-one
#       error.
# 
#     
#   2.  At i = 1, it compares text1[1] with text2[1], skipping the first characters (text1[0], text2[0]). This shifts all comparisons and 
#       gives wrong LCS lengths.
