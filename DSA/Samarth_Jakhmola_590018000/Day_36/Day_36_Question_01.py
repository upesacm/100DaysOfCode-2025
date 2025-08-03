def reverse_string(string):
    stack = []
    for i in string:
        stack.append(i)

    reverse = ""
    while stack:
        reverse += stack.pop()

    return reverse

try:
    string = input("Enter a string : ")
    print(f"\"{reverse_string(string)}\"")
except:
    print("Invalid input. Please try with a valid input.")
