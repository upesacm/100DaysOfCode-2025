# Check if a Number is Power of 2
n = int(input("Enter a number: "))
if n > 0 and (n & (n - 1)) == 0:
    print("Yes")
else:
    print("No")
