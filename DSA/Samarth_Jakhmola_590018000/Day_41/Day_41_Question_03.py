def remove_k_digits(string, k):
    stack = []

    for digit in string:
        # Greedy Removal : Remove digits while they are bigger than current digit.
        while k > 0 and stack and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)

    # If there are any digits left to remove, remove from the end (largest at end)
    while k > 0:
        stack.pop()
        k -= 1

    # Remove leading zeroes and convert to string
    result = ''.join(stack).lstrip('0')
    return result if result else "0"

try:
    string = input("Enter the string : ")
    k = int(input("Enter the value of k : "))
    print(f"\"{remove_k_digits(string, k)}\"")
except:
    print("Invalid input. Please try with a valid input.")
