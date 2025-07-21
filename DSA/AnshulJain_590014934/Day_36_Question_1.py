stack = []
s = input("Enter a string to reverse: ") #taking input from the user 
for char in s:
    stack.append(char)
reversed_s = ''
while stack:
    reversed_s += stack.pop()
print(reversed_s)
#for exmaple:-
# Input: Hello World
# Output: dlroW olleH
