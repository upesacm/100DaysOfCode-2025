struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL)
        return NULL;

    struct Node* temp = head;


    if (x == 1) {
        head = temp->next;
        free(temp);
        return head;
    }

  
    for (int i = 1; temp != NULL && i < x - 1; i++)
        temp = temp->next;

   
    if (temp == NULL || temp->next == NULL)
        return head;

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;

    return head;
}
