#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

int linkedListToInt(struct Node* head) {
    int num = 0;
    while (head != NULL) {
        num = num * 10 + head->data;
        head = head->next;
    }
    return num;
}

struct Node* intToList(int num) {
    if (num == 0)
        return createNode(0);

    int digits[20]; 
    int count = 0;

    while (num > 0) {
        digits[count++] = num % 10;
        num /= 10;
    }

    struct Node* head = NULL;
    for (int i = count - 1; i >= 0; i--) {
        head = appendNode(head, digits[i]);
    }
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

struct Node* takeInput() {
    int n, val;
    struct Node* head = NULL;
    printf("Enter number of digits: ");
    scanf("%d", &n);
    printf("Enter digits (MSD to LSD):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = appendNode(head, val);
    }
    return head;
}

int main() {
    printf("Enter first number:\n");
    struct Node* num1 = takeInput();

    printf("Enter second number:\n");
    struct Node* num2 = takeInput();

    int number1 = linkedListToInt(num1);
    int number2 = linkedListToInt(num2);
    int sum = number1 + number2;

    struct Node* result = intToList(sum);

    printf("Sum: ");
    printList(result);

    return 0;
}
