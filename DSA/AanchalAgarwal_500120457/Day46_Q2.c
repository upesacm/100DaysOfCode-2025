void countEvenOdd(Queue* q, int* evenCount, int* oddCount) {
    *evenCount = 0;
    *oddCount = 0;
    int size = getSize(q);

    for (int i = 0; i < size; i++) {
        int val = dequeue(q);
        if (val % 2 == 0)
            (*evenCount)++;
        else
            (*oddCount)++;
        enqueue(q, val);  // Restore
    }
}

