#: Design a dual-stack array implementation with optimal space utilization by managing dynamic boundaries and preventing premature overflow conditions.
size = int(input("Enter the total size of the array: "))

arr = [None] * size
top1 = -1
top2 = size

while True:
    print("\n1. Push Stack 1")
    print("2. Push Stack 2")
    print("3. Pop Stack 1")
    print("4. Pop Stack 2")
    print("5. Print Both Stacks")
    print("6. Exit")
    
    choice = int(input("Enter choice: "))
    
    if choice == 1:
        val = int(input("Enter value to push in Stack 1: "))
        if top1 + 1 < top2:
            top1 += 1
            arr[top1] = val
        else:
            print("Stack Overflow!")
    
    elif choice == 2:
        val = int(input("Enter value to push in Stack 2: "))
        if top1 < top2 - 1:
            top2 -= 1
            arr[top2] = val
        else:
            print("Stack Overflow!")
    
    elif choice == 3:
        if top1 >= 0:
            print("Popped from Stack 1:", arr[top1])
            top1 -= 1
        else:
            print("Stack 1 Underflow!")
    
    elif choice == 4:
        if top2 < size:
            print("Popped from Stack 2:", arr[top2])
            top2 += 1
        else:
            print("Stack 2 Underflow!")
    
    elif choice == 5:
        print("Stack 1:", arr[:top1+1])
        print("Stack 2:", arr[top2:])
    
    elif choice == 6:
        break
    
    else:
        print("Invalid choice! Try again.")
