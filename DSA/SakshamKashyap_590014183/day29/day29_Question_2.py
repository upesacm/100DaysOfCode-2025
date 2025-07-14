def Get_ith_bit(num,ith):
    result = num & (1<<ith)
    print(result)

n = int(input("Enter the number please: "))
ith = int(input("Enter the value of a specific bit position you want to check: "))
Get_ith_bit(n,ith)