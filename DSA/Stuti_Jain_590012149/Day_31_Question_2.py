a=int(input("enter a number: "))

sm=a^a
carry=(a&a)<<1
result=sm^carry

print(result)
