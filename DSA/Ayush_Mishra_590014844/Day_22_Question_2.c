int countFrequency(struct Node* head, int key) {
    int count = 0;
    while (head) {
        if (head->data == key) count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter key to count: ");
    scanf("%d", &key);

    struct Node* head = createLinkedList(arr, n);
    printf("Frequency of %d: %d\n", key, countFrequency(head, key));
    return 0;
}
