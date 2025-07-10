def middleNode(head):
    slow = fast = 0
    while fast < len(head) - 1 and fast + 1 < len(head) - 1:
        slow += 1
        fast += 2
    return head[slow]
linked_list = [1, 2, 3, 4, 5]
middle = middleNode(linked_list)
print(middle)