struct Node* del_mid(struct Node* head) {
    if (!head || !head->next) return NULL;

    int count = 0;
    struct Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;
    temp = head;
    for (int i = 0; i < mid - 1; i++)
        temp = temp->next;

    struct Node* to_del = temp->next;
    temp->next = temp->next->next;
    free(to_del);  // free memory

    return head;
}
