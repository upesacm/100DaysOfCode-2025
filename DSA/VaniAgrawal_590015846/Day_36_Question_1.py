# Utilize a stack's LIFO property to reverse string characters by pushing all characters and then popping them sequentially. 
def reverse_string():
    s = input("Enter a string: ")
    stack = []
    for ch in s:
        stack.append(ch)
    
    reversed_str = ''
    while stack:
        reversed_str += stack.pop()
    
    print("Reversed string:", reversed_str)

reverse_string()
