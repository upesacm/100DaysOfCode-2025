void mergeQueues(Queue* q1, Queue* q2) {
    int size = getSize(q2);
    for (int i = 0; i < size; i++) {
        int val = dequeue(q2);
        enqueue(q1, val);  // Append from q2 to q1
    }
}

