def delete_middle(stack, current, middle):
    if current == middle:
        stack.pop()
        return
    temp = stack.pop()
    delete_middle(stack, current + 1, middle)
    stack.append(temp)

def delete_middle_element(stack):
    if not stack:
        return
    middle_pos = len(stack) // 2 + 1
    delete_middle(stack, 1, middle_pos)

def main():
    input_str = input("Enter stack elements separated by spaces: ").strip()
    if not input_str:
        print("[]")
        return
    stack = list(map(int, input_str.split()))
    delete_middle_element(stack)
    print(stack)

if __name__ == "__main__":
    main()