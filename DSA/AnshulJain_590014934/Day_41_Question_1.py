def remove_adjacent_duplicates(string):
    stack=[]
    for char in string:
        if stack and stack[-1]==char:
            stack.pop()
        else:
            stack.append(char)
    return ''.join(stack)

input_str = input("Enter a string: ")#Taking input from the user 
print(remove_adjacent_duplicates(input_str))
#for example:
# Input: "abbaca"
# Output: "ca"