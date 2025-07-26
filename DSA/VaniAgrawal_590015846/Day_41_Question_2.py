# Implement dual-stack parsing to handle nested bracket structures with numerical multipliers for accurate recursive string expansion. 
s = input("Enter the encoded string: ")

stack = []
num = 0
curr_str = ''

for char in s:
    if char.isdigit():
        num = num * 10 + int(char)  
    elif char == '[':
        stack.append((curr_str, num))
        curr_str = ''
        num = 0
    elif char == ']':
        prev_str, repeat = stack.pop()
        curr_str = prev_str + curr_str * repeat
    else:
        curr_str += char

print("Output:", curr_str)
