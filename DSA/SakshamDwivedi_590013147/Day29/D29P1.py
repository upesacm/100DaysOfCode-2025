#Approach 1 using OR
def odd_even_or(num):
    if(num | 1 == num):
        return "Odd"
    else:
        return "Even"

#Approach 2 using AND
def odd_even_and(num):
    if(num & 1):
        return "Odd"
    else:
        return "Even"

#Approach 3 using XOR
def odd_even_xor(num):
    if((num ^ 1) == (num + 1)):
        return "Even"
    else:
        return "Odd"

#Fixed Input
print(odd_even_or(5))
print(odd_even_or(4))
print(odd_even_and(5))
print(odd_even_and(4))
print(odd_even_xor(5))
print(odd_even_xor(4))

#Custom Input
num = int(input("Enter the number : "))
print(odd_even_or(num))
print(odd_even_and(num))
print(odd_even_xor(num))
