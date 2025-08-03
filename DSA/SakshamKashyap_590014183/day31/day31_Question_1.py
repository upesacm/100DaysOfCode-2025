def power_of_2(n):
    if n <= 0:
        return "No"
    if n & (n-1) == 0:
        return "Yes"
    else:
        return "No"

num = int(input("Enter the number: "))
result= power_of_2(num)

print(result)

