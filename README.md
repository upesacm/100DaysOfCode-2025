<h2 align="center">Day 26 (11/07/2025)</h2>

## 1. Swap Kth nodes from ends
A problem that introduces advanced linked list manipulation techniques and teaches how to swap nodes at symmetric positions efficiently using pointer operations.

Given a **singly linked list** and an integer **k**, you need to swap the **kth node from the beginning** and the **kth node from the end** of the linked list. Swap the nodes through the **links**, not by changing the content of the nodes. This problem appears frequently in **interviews** and **real-world applications** like implementing symmetric operations, data rearrangement, or palindrome creation algorithms. The challenge involves finding the correct nodes to swap and properly handling all the pointer connections without breaking the list structure.

This teaches **symmetric node manipulation** and **complex pointer operations** that are essential for **advanced linked list transformations and positional swapping algorithms**.

**Your task:** Swap nodes at symmetric positions by manipulating pointers while maintaining list integrity and handling edge cases.

### Examples

**Input:**
```
LinkedList: 1->2->3->4, k = 1
```
**Output:**
```
true
```

---

**Input:**
```
LinkedList: 1->2->3->4->5, k = 7
```
**Output:**
```
true
```

---

## 2. Union of Two Linked Lists
A problem that demonstrates set operations on linked lists and teaches how to combine two lists while eliminating duplicates and maintaining sorted order.

Given **two linked lists** (L1 & L2), your task is to complete the function makeUnion(), which returns the **union list** of two linked lists. This union list should include all the **distinct elements only** and it should be **sorted in ascending order**. This operation is fundamental in **data merging** and **set operations** where you need to **combine datasets while removing duplicates** and maintaining order. The challenge involves efficiently handling duplicates and sorting the final result.

This introduces **set union operations** and **duplicate elimination techniques** that are crucial for **data consolidation and efficient list merging operations**.

**Your task:** Create union of two linked lists with distinct elements in sorted order using efficient merging and deduplication.

### Examples

**Input:**
```
L1 = 9->6->4->2->3->8, L2 = 1->2->8->6->2
```
**Output:**
```
1 -> 2 -> 3 -> 4 -> 6 -> 8 -> 9
```

---

**Input:**
```
L1 = 1->5->1->2->2->5, L2 = 4->5->6->7->1
```
**Output:**
```
1 -> 2 -> 4 -> 5 -> 6 -> 7
```

---

## 3. Sort a linked list of 0s, 1s and 2s
A problem that teaches specialized sorting techniques and demonstrates how to rearrange linked lists with limited value domains efficiently.

Given the **head of a linked list** where nodes can contain values **0s, 1s, and 2s only**, your task is to rearrange the list so that all **0s appear at the beginning**, followed by all **1s**, and all **2s are placed at the end**. This is a variation of the **Dutch National Flag problem** applied to linked lists and is commonly used in **data preprocessing** and **categorical sorting** applications. You can solve this by counting occurrences first, but try to think of **more efficient approaches** using three-pointer technique or node rearrangement.

This teaches **categorical sorting** and **three-way partitioning** techniques that are essential for **specialized sorting algorithms and efficient data categorization**.

**Your task:** Sort a linked list containing only 0s, 1s, and 2s using efficient partitioning techniques without extra space.

### Examples

**Input:**
```
head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
```
**Output:**
```
0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
```

---

**Input:**
```
head = 2 → 2 → 0 → 1
```
**Output:**
```
0 → 1 → 2 → 2
```
