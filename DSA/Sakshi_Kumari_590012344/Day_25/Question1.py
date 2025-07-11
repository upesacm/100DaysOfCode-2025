class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

def create_linked_list(numbers):
    if not numbers:
        return None
    head = Node(numbers[0])
    current = head
    for num in numbers[1:]:
        current.next = Node(num)
        current = current.next
    return head

def is_palindrome(head):
    values = []
    current = head
    while current is not None:
        values.append(current.data)
        current = current.next
    if values == values[::-1]:
        return True
    else:
        return False
user_input = input("Enter numbers for the linked list (separated by space): ").strip()

if user_input == "":
    print("The list is empty.")
else:
    try:
        elements = list(map(int, user_input.split()))
        head = create_linked_list(elements)
        if is_palindrome(head):
            print("The linked list is a palindrome.")
        else:
            print("The linked list is not a palindrome.")
    except:
        print("Please enter only valid numbers.")
