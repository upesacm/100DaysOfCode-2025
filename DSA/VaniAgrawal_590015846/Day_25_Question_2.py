# Find intersection of two sorted linked lists by creating a new list while preserving original lists.
list1 = list(map(int, input("Enter elements of LinkedList1: ").split()))
list2 = list(map(int, input("Enter elements of LinkedList2: ").split()))

i, j = 0, 0
intersection = []

while i < len(list1) and j < len(list2):
    if list1[i] == list2[j]:
        intersection.append(list1[i])
        i += 1
        j += 1
    elif list1[i] < list2[j]:
        i += 1
    else:
        j += 1

if intersection:
    print(" -> ".join(map(str, intersection)))
else:
    print("No intersection")
