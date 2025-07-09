void skipMdeleteN(struct Node* head, int m, int n) {
    struct Node* curr = head;
    struct Node* temp;
    int count;

    while (curr) {
       
        for (count = 1; count < m && curr != NULL; count++)
            curr = curr->next;

        if (curr == NULL)
            return;

     
        temp = curr->next;
        for (count = 1; count <= n && temp != NULL; count++) {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }

       t
        curr->next = temp;
        curr = temp;
    }
}
