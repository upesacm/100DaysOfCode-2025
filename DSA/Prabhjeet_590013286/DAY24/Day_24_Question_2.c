struct Node* skip_del(struct Node* head, int m, int n) {
    struct Node* curr = head;
    while (curr) {
        for (int i = 1; i < m && curr; i++)
            curr = curr->next;

        if (!curr) break;

        struct Node* temp = curr->next;
        for (int i = 0; i < n && temp; i++) {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }

        curr->next = temp;
        curr = temp;
    }
    return head;
}
