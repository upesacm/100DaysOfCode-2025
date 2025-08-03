# 2. Check for Balanced Parenthese
def are_parentheses_balanced(s: str) -> bool:
    """
    Checks if a string has balanced parentheses using a stack.

    This function validates strings containing '()', '{}', and '[]'. It uses
    a stack to track opening brackets and ensures they are matched with the
    correct closing brackets in the correct order.

    Args:
        s: The string containing parentheses.

    Returns:
        True if the parentheses are balanced, False otherwise.
    """
    stack = []
    bracket_map = {")": "(", "}": "{", "]": "["}
    
    for char in s:
        if char in bracket_map:
            if not stack or stack[-1] != bracket_map[char]:
                return False
            stack.pop() 
        else:
            stack.append(char)
    return not stack

if __name__ == "__main__":
    input_paren1 = "([])"
    result1 = "Balanced" if are_parentheses_balanced(input_paren1) else "Not Balanced"
    print(f'Input: "{input_paren1}"')
    print(f'Output: {result1}')
    input_paren2 = "(["
    result2 = "Balanced" if are_parentheses_balanced(input_paren2) else "Not Balanced"
    print(f'\nInput: "{input_paren2}"')
    print(f'Output: {result2}')  
    input_paren3 = "([)]"
    result3 = "Balanced" if are_parentheses_balanced(input_paren3) else "Not Balanced"
    print(f'\nInput: "{input_paren3}"')
    print(f'Output: {result3}')  