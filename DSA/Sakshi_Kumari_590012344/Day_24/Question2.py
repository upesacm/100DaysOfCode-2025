Your task: Delete nodes following a specific pattern while maintaining proper list 
connections and handling edge cases.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def delete_n_after_m(head, m, n):
    current = head

    while current:
        for _ in range(1, m):
            if current is None:
                return head
            current = current.next

        if current is None or current.next is None:
            break
        temp = current.next
        for _ in range(n):
            if temp is None:
                break
            temp = temp.next
        current.next = temp
        current = temp

    return head
