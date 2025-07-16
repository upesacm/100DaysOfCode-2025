n = int(input("Enter The Number:"))#Taking input from the user 
if n > 0 and (n & (n - 1)) == 0:
    print("Yes")
else:
    print("No")
#for example:
# Input: 8
# Output: Yes
