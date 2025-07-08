struct Node* rem_dups(struct Node* head) {
    struct Node* curr = head;
    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            struct Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);  
        } else {
            curr = curr->next;
        }
    }
    return head;
}
