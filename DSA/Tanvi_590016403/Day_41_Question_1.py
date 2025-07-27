def remove_adjacent_duplicates(s: str) -> str:
    while True:
        stack = []
        changed = False
        i = 0
        while i < len(s):
            if stack and stack[-1] == s[i]:
                stack.pop()
                changed = True
            else:
                stack.append(s[i])
            i += 1
        s = ''.join(stack)
        if not changed:
            break
    return s

def decode_string(s: str) -> str:
    stack = []
    current_num = 0
    current_str = ''
    
    for char in s:
        if char.isdigit():
            current_num = current_num * 10 + int(char)
        elif char == '[':
            stack.append((current_str, current_num))
            current_str = ''
            current_num = 0
        elif char == ']':
            prev_str, num = stack.pop()
            current_str = prev_str + current_str * num
        else:
            current_str += char
    return current_str

def remove_k_digits(num: str, k: int) -> str:
    stack = []
    for digit in num:
        while stack and k > 0 and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)
    
    stack = stack[:-k] if k else stack
    result = ''.join(stack).lstrip('0')
    return result if result else "0"

def main():
    print("Choose a problem to solve:")
    print("1. Remove Adjacent Duplicates")
    print("2. Decode a String")
    print("3. Remove K Digits to Make the Smallest Number")

    choice = input("Enter your choice (1/2/3): ").strip()

    if choice == '1':
        s = input("Enter a string: ")
        print("Reduced string:", remove_adjacent_duplicates(s))

    elif choice == '2':
        s = input("Enter encoded string (e.g. 3[a2[c]]): ")
        print("Decoded string:", decode_string(s))

    elif choice == '3':
        num = input("Enter the number: ")
        k = int(input("Enter number of digits to remove (k): "))
        print("Smallest number:", remove_k_digits(num, k))

    else:
        print("Invalid choice.")

if __name__ == "__main__":
    main()
