#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertEnd(struct Node *head, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (!head)
        return newNode;

    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;

    return head;
}

int countFrequency(struct Node *head, int key)
{
    int count = 0;
    while (head)
    {
        if (head->data == key)
            count++;
        head = head->next;
    }
    return count;
}

int main()
{
    struct Node *head = NULL;
    int n, val, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    printf("Enter key to find frequency: ");
    scanf("%d", &key);

    int freq = countFrequency(head, key);
    printf("Frequency of %d: %d\n", key, freq);

    return 0;
}
