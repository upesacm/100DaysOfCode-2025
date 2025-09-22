#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ---------------- Problem 1: Array Sum + Vowel Count ----------------
int sumPositive(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            sum += arr[i];
    }
    return sum;
}

int countVowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}

// ---------------- Problem 2: Stack-based Maximum Window ----------------
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->data = (int*)malloc(capacity * sizeof(int));
    return s;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int val) {
    if (s->top < s->capacity - 1) {
        s->data[++s->top] = val;
    }
}

int pop(Stack* s) {
    if (!isEmpty(s))
        return s->data[s->top--];
    return -1;
}

int peek(Stack* s) {
    if (!isEmpty(s))
        return s->data[s->top];
    return -1;
}

// Sliding window maximum using two stacks (monotonic style)
void maxSlidingWindow(int arr[], int n, int k) {
    Stack* s1 = createStack(n);
    Stack* s2 = createStack(n);
    int *output = (int*)malloc((n - k + 1) * sizeof(int));
    int idx = 0;

    for (int i = 0; i < n; i++) {
        push(s1, arr[i]);

        if (i >= k - 1) {
            if (isEmpty(s2)) {
                while (!isEmpty(s1)) {
                    int val = pop(s1);
                    int maxVal = isEmpty(s2) ? val : (val > peek(s2) ? val : peek(s2));
                    push(s2, maxVal);
                }
            }
            output[idx++] = peek(s2);

            // Slide window: remove leftmost
            if (arr[i - k + 1] == peek(s2))
                pop(s2);
        }
    }

    printf("Sliding Window Maximums: ");
    for (int i = 0; i < idx; i++)
        printf("%d ", output[i]);
    printf("\n");

    free(s1->data); free(s1);
    free(s2->data); free(s2);
    free(output);
}

// ---------------- Problem 3: Tree Max Path Sum (DP) ----------------
struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxPathUtil(struct Node* root, int *res) {
    if (root == NULL) return 0;

    int l = maxPathUtil(root->left, res);
    int r = maxPathUtil(root->right, res);

    int max_single = max(max(l, r) + root->val, root->val);
    int max_top = max(max_single, l + r + root->val);

    if (max_top > *res)
        *res = max_top;

    return max_single;
}

int maxPathSum(struct Node* root) {
    int res = -1000000;
    maxPathUtil(root, &res);
    return res;
}

// ---------------- Main ----------------
int main() {
    // Problem 1
    int arr1[] = {1, -2, 3, -4, 5};
    char str[] = "Hello World";
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Sum of positives: %d\n", sumPositive(arr1, n1));
    printf("Vowel count: %d\n", countVowels(str));

    // Problem 2
    int arr2[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k = 3;
    maxSlidingWindow(arr2, n2, k);

    // Problem 3
    struct Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);

    printf("Maximum Path Sum in Tree: %d\n", maxPathSum(root));

    return 0;
}
