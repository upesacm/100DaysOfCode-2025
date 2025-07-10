int kend(struct Node* head, int k) {
    int count = 0;
    struct Node* temp = head;
  
    while (temp) {
        count++;
        temp = temp->next;
    }

    // If k is greater than count, return -1
    if (k > count) return -1;

    // Second pass: reach the (count - k)th node
    temp = head;
    for (int i = 0; i < count - k; i++)
        temp = temp->next;

    return temp->data;
}
