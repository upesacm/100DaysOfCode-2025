# Design a stack with auxiliary maximum tracking to maintain peak element information while ensuring all operations remain O(1) complexity.
main_stack = []
max_stack = []

while True:
    command = input("Enter command (push <num> / pop / getMax / exit): ").strip().lower()
    
    if command.startswith("push"):
        num = int(command.split()[1])
        main_stack.append(num)
        if not max_stack or num >= max_stack[-1]:
            max_stack.append(num)
        else:
            max_stack.append(max_stack[-1])
    
    elif command == "pop":
        if main_stack:
            popped = main_stack.pop()
            max_stack.pop()
            print("Popped:", popped)
        else:
            print("Stack is empty.")
    
    elif command == "getmax":
        if max_stack:
            print("Max:", max_stack[-1])
        else:
            print("Stack is empty.")
    
    elif command == "exit":
        break
    
    else:
        print("Invalid command. Use push <num>, pop, getMax, or exit.")
