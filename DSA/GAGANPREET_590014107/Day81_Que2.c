
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

struct List {
    int val;
    struct List *next;
};

void bst_to_list(struct Node *root, struct List **tail) {
    if (root == NULL)
        return;

    bst_to_list(root->left, tail);

    struct List *new_node = (struct List *)malloc(sizeof(struct List));
    new_node->val = root->val;
    new_node->next = NULL;
    (*tail)->next = new_node;
    *tail = new_node;

    bst_to_list(root->right, tail);
}

void print_list(struct List *head) {
    struct List *cur = head->next;
    while (cur) {
        printf("%d", cur->val);
        if (cur->next)
            printf(" -> ");
        cur = cur->next;
    }
    printf("\n");
}


int main() {
    struct Node a = {4, NULL, NULL};
    struct Node b = {2, NULL, NULL};
    struct Node c = {6, NULL, NULL};
    struct Node d = {1, NULL, NULL};
    struct Node e = {3, NULL, NULL};
    struct Node f = {5, NULL, NULL};
    struct Node g = {7, NULL, NULL};

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    struct List dummy = {0, NULL};
    struct List *tail = &dummy;

    bst_to_list(&a, &tail);
    print_list(&dummy);  
    return 0;
}
