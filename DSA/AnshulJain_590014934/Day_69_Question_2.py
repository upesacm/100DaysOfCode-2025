arr=list(map(int,input("Enter the array:-").split()))
s=sum(arr)
if s%2!=0:
    print("false")
else:
    target=s//2
    dp={0}
    for num in arr:
        dp|={x+num for x in dp}
    print("true" if target in dp else "false")
