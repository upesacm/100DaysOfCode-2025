s=input("Enter the input:")
f={}
for c in s:
    f[c]=f.get(c,0)+1
odd=sum(v%2 for v in f.values())
print("Yes" if odd<=1 else "No")
# for example:-
# input = civic
# output = yes