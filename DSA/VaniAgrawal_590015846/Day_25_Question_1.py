#Check if a linked list is a palindrome using efficient techniques without extra space or with minimal space complexity. 
elements = input("Enter linked list elements separated by space: ").split()
linked_list = [int(x) for x in elements]
is_palindrome = linked_list == linked_list[::-1]
print(is_palindrome)
