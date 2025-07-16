def multiply_by_two(n):
    result = n << 1
    return result
number = int(input("Enter a number: "))
answer = multiply_by_two(number)
print("After multiplying", number, "by 2, the result is:", answer)

