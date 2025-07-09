struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* curr = head;
    for (int i = 1; curr != NULL && i < pos - 1; i++) curr = curr->next;
    if (curr == NULL || curr->next == NULL) return head;
    struct Node* del = curr->next;
    curr->next = curr->next->next;
    free(del);
    return head;
}

// Add this logic inside main after creating the list:
int pos;
printf("Enter position to delete (1-based index): ");
scanf("%d", &pos);
head = deleteAtPosition(head, pos);
printf("After Deletion: ");
printList(head);
