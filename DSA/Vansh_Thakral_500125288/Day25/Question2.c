struct Node* intersect(struct Node* head1, struct Node* head2) {
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data == head2->data) {
            tail->next = newNode(head1->data);
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }
    return dummy->next;
}
