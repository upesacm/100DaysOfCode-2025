def decode_string(string):
    stack = []
    current_string = ''
    num = 0

    for ch in string:
        if ch.isdigit():
            num = num * 10 + int(ch)
        elif ch == '[':
            stack.append((current_string, num))
            current_string = ''
            num = 0
        elif ch == ']':
            prev_str, k = stack.pop()
            current_string = prev_str + current_string * k    # Expanding and merging
        else:
            current_string += ch    # Accumulating characters

    return current_string

try:
    string = input("Enter the string : ")
    print(f"\"{decode_string(string)}\"")
except:
    print("Invalid input. Please try with a valid input.")
