int kend(struct Node* head, int k) {
    int count = 0;
    struct Node* temp = head;

    while (temp) {
        count++;
        temp = temp->next;
    }

    if (k > count) return -1;

    temp = head;
    for (int i = 0; i < count - k; i++)
        temp = temp->next;

    return temp->data;
}
