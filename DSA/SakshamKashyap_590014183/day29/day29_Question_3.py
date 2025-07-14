def Set_ith_bit(num,ith):
    print(num | (1<<ith))
n = int(input("Enter the number please: "))
ith = int(input("Enter the value of a specific bit position you want to check: "))
Set_ith_bit(n,ith)