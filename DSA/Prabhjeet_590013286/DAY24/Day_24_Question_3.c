struct Node* del_pos(struct Node* head, int x) {
    if (!head) return NULL;

    if (x == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    for (int i = 1; i < x - 1 && curr; i++)
        curr = curr->next;

    if (!curr || !curr->next) return head;

    struct Node* del = curr->next;
    curr->next = curr->next->next;
    free(del);

    return head;
}
