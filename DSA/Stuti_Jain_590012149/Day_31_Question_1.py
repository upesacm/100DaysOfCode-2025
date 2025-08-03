n=int(input("enter a number: "))

if n>0 and (n&(n-1))==0:
    print("Yes")
else:
    print("No")
