<h2 align="center">Day 47 (01/08/2025)</h2>

## 1. Insert Element at Rear of Queue  
A basic yet essential operation in queue handling that introduces the concept of **enqueueing** elements at the rear for standard FIFO behavior. This builds a strong foundation in **linear data structure manipulation**.

Write a function that inserts a given element at the rear of a queue and returns the updated queue.

This teaches **rear insertion**, **queue dynamics**, and is fundamental to **real-time systems**, **task scheduling**, and **data buffering**.

**Your task:** Insert an element at the end of a queue and return the updated queue.

### Examples

**Input:**
```
Queue = [1, 2], Insert = 3
```
**Output:**
```
[1, 2, 3]
```

---

**Input:**
```
Queue = [4, 5], Insert = 6
```
**Output:**
```
[4, 5, 6]
```

---

## 2. Insert Element at Front of Queue  
An operation that demonstrates **priority queue behavior** by adding elements to the front, which is useful in **task reordering**, **interrupt handling**, and **control systems**.

Write a function to insert a given element at the front of a queue.

This teaches **front insertion**, **queue prioritization**, and **head adjustment techniques** useful in **data streams** and **real-time control queues**.

**Your task:** Add an element to the front of a queue and return the updated queue.

### Examples

**Input:**
```
Queue = [2, 3, 4], Insert = 1
```
**Output:**
```
[1, 2, 3, 4]
```

---

**Input:**
```
Queue = [7, 8], Insert = 6
```
**Output:**
```
[6, 7, 8]
```

---

## 3. Find the Front and Rear of the Queue  
A diagnostic operation to retrieve **boundary elements** of a queue without altering it — useful for **monitoring**, **status checks**, and **queue visualization**.

Write a function that returns the front and rear elements of a queue without modifying it. If the queue is empty, return an appropriate message.

This teaches **non-destructive access**, **queue boundary analysis**, and helps in **queue status validation** in various applications.

**Your task:** Retrieve the front and rear of the queue or return an empty message.

### Examples

**Input:**
```
Queue = [10, 20, 30]
```
**Output:**
```
Front: 10, Rear: 30
```

---

**Input:**
```
Queue = []
```
**Output:**
```
Queue is empty
```

---

