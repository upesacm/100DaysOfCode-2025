struct Node* deleteNafterM(struct Node* head, int m, int n) {
    struct Node* curr = head;
    struct Node* temp;
    int i;
    while (curr) {
        for (i = 1; i < m && curr != NULL; i++) curr = curr->next;
        if (curr == NULL) break;
        temp = curr->next;
        for (i = 0; i < n && temp != NULL; i++) {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }
        curr->next = temp;
        curr = temp;
    }
    return head;
}

// Add this logic inside main after creating the list:
int m, n;
printf("Enter M and N: ");
scanf("%d %d", &m, &n);
head = deleteNafterM(head, m, n);
printf("Modified List: ");
printList(head);
