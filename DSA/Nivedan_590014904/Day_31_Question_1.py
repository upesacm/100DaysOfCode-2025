n = int(input("Enter the value of n: "))
count =0 
while n!= 0:
    n = n&(n-1)
    count+=1
if count == 1:
    print("Yes it's a power of 2")
else:
    print("No it's not a power of 2")
