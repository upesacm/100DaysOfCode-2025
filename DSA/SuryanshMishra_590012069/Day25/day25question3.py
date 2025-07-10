# 3. Add Number Linked Lists
# A problem that teaches arithmetic operations on linked list representations and demonstrates how to perform addition on numbers stored as linked lists.

# Given the head of two singly linked lists num1 and num2 representing two non-negative integers, the task is to return the head of the linked list representing the sum of these two numbers. For example, num1 represented by the linked list: 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5. There can be leading zeros in the input lists, but there should not be any leading zeros in the output list. This problem simulates big number arithmetic commonly used in cryptography and mathematical computations.

# This teaches digit-by-digit arithmetic and carry propagation techniques that are essential for big number operations and mathematical computations in linked structures.

# Your task: Add two numbers represented as linked lists while handling carry propagation and leading zero elimination.

# Examples
# Input:

# num1 = 4 -> 5, num2 = 3 -> 4 -> 5
# Output:

# 3 -> 9 -> 0
# Input:

# num1 = 0 -> 0 -> 6 -> 3, num2 = 0 -> 7
# Output:

# 7 -> 0
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def getLength(head):
    length = 0
    while head:
        length += 1
        head = head.next
    return length

def padList(head, padding):
    for _ in range(padding):
        newNode = ListNode(0)
        newNode.next = head
        head = newNode
    return head

def addListsHelper(l1, l2):
    if not l1 and not l2:
        return (0, None)

    carry, next_node = addListsHelper(l1.next, l2.next)

    total = l1.val + l2.val + carry
    node = ListNode(total % 10)
    node.next = next_node

    return (total // 10, node)

def addTwoNumbers(num1: ListNode, num2: ListNode) -> ListNode:
    len1 = getLength(num1)
    len2 = getLength(num2)

    # Pad the shorter list
    if len1 < len2:
        num1 = padList(num1, len2 - len1)
    else:
        num2 = padList(num2, len1 - len2)

    carry, result = addListsHelper(num1, num2)

    # If there's a leftover carry, add a new node
    if carry:
        newHead = ListNode(carry)
        newHead.next = result
        return newHead

    return result
