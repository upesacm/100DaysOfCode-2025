<h2 align="center">Day 27 (12/07/2025)</h2>

## 1. Delete in a Doubly Linked List
A problem that introduces doubly linked list manipulation techniques and teaches how to delete nodes while maintaining bidirectional pointer connections.

Given a **Doubly Linked list** and a **position**, the task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly linked list. This problem appears frequently in **interviews** and **real-world applications** like implementing browser history navigation, undo-redo operations, or music playlist management. The challenge involves properly handling **both forward and backward pointers** while maintaining list integrity and managing edge cases like deleting the head or tail node.

This teaches **bidirectional pointer manipulation** and **doubly linked list operations** that are essential for **complex data structure management and efficient two-way navigation systems**.

**Your task:** Delete a node at a specific position in a doubly linked list while maintaining proper forward and backward connections.

### Examples

**Input:**
```
LinkedList = 1 <--> 3 <--> 4, x = 3
```
**Output:**
```
1 <--> 3
```

---

**Input:**
```
LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
```
**Output:**
```
5 <--> 2 <--> 9
```

---

## 2. Reverse a Doubly Linked List
A problem that demonstrates advanced linked list reversal techniques and teaches how to reverse bidirectional connections efficiently.

Given a **doubly linked list**, your task is to **reverse the doubly linked list** and return its head. This operation is fundamental in **data structure manipulation** and **navigation systems** where you need to **change the direction of traversal** while maintaining both forward and backward connectivity. The challenge involves swapping both the next and previous pointers for each node, which is more complex than reversing a singly linked list.

This introduces **bidirectional reversal** and **pointer swapping techniques** that are crucial for **advanced data structure transformations and efficient navigation system implementations**.

**Your task:** Reverse a doubly linked list by swapping both forward and backward pointers for all nodes.

### Examples

**Input:**
```
LinkedList: 3 <-> 4 <-> 5
```
**Output:**
```
5 <-> 4 <-> 3
```

---

**Input:**
```
LinkedList: 75 <-> 122 <-> 59 <-> 196
```
**Output:**
```
196 <-> 59 <-> 122 <-> 75
```

---

## 3. Remove every k'th node
A problem that teaches interval-based node deletion and demonstrates how to remove nodes following a specific pattern while maintaining list structure.

Given a **singly linked list**, your task is to **remove every kth node** from the linked list. This operation is commonly used in **data sampling** and **periodic filtering** applications where you need to **eliminate elements at regular intervals** for data reduction or pattern-based processing. The challenge involves maintaining proper node connections while counting positions and handling the deletion pattern throughout the entire list.

This teaches **interval-based deletion** and **pattern-based traversal** techniques that are essential for **data filtering and systematic element removal operations**.

**Your task:** Remove every kth node from a linked list while maintaining proper connections and handling edge cases.

### Examples

**Input:**
```
Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, k = 2
```
**Output:**
```
1 -> 3 -> 5 -> 7
```

---

**Input:**
```
Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10, k = 3
```
**Output:**
```
1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
```
