# 1. Reverse a String using Stack
def reverse_string_with_stack(s: str) -> str:
    """
    Reverses a string using a stack (implemented with a list).

    This function pushes all characters of the input string onto a stack
    and then pops them off to build the reversed string, demonstrating the
    Last-In-First-Out (LIFO) principle.

    Args:
        s: The input string to be reversed.

    Returns:
        The reversed string.
    """
    stack = []
    for char in s:
        stack.append(char)
    
    reversed_s = ""
    while stack:
        reversed_s += stack.pop()
        
    return reversed_s

if __name__ == "__main__":
    input_str1 = "hello"
    print(f'Input: "{input_str1}"')
    print(f'Output: "{reverse_string_with_stack(input_str1)}"') 
    input_str2 = "abcde"
    print(f'\nInput: "{input_str2}"')
    print(f'Output: "{reverse_string_with_stack(input_str2)}"')  