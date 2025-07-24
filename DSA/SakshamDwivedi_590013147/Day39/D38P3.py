size = 100
arr = [0] * size
top1 = -1
top2 = size

def push(stack_num, val):
    global top1, top2, arr

    if top1 < top2 - 1:
        if stack_num == 1:
            top1 += 1
            arr[top1] = val
        elif stack_num == 2:
            top2 -= 1
            arr[top2] = val
        else:
            print("Invalid stack number!")
    else:
        print("Stack Overflow!")

def pop(stack_num):
    global top1, top2, arr

    if stack_num == 1:
        if top1 >= 0:
            val = arr[top1]
            top1 -= 1
            return val
        else:
            print("Stack 1 Underflow!")
            return None

    elif stack_num == 2:
        if top2 < size:
            val = arr[top2]
            top2 += 1
            return val
        else:
            print("Stack 2 Underflow!")
            return None

    else:
        print("Invalid stack number!")
        return None

def display():
    print("Stack1:", arr[:top1+1])
    print("Stack2:", arr[top2:])

#Custom Input
con = "y"
while con == "y" or con == "Y":
    print("\n1. Push to Stack 1")
    print("2. Push to Stack 2")
    print("3. Pop from Stack 1")
    print("4. Pop from Stack 2")
    print("5. Display Stacks")
    print("6. Exit")

    ch = int(input("Enter choice: "))

    match ch:
        case 1:
            val = int(input("Enter value to push to Stack 1: "))
            push(1, val)
        case 2:
            val = int(input("Enter value to push to Stack 2: "))
            push(2, val)
        case 3:
            print("Popped from Stack 1:", pop(1))
        case 4:
            print("Popped from Stack 2:", pop(2))
        case 5:
            display()
        case 6:
            break
        case _:
            print("Invalid choice!")
    con = input("Enter y to continue or n to exit : ")
