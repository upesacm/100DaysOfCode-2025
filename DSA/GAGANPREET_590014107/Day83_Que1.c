#include <stdio.h>
#include <stdlib.h>

#define MAX 1000


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};


struct QNode
{
    struct Node* node;
    int hd;
};


struct Node* create(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}


struct QNode queue[MAX];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd)
{
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode dequeue()
{
    return queue[front++];
}


struct Node* map[MAX];
int mapCount[MAX] = {0};


void vertical(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    enqueue(root, MAX / 2);  

    while (front < rear)
    {
        struct QNode temp = dequeue();
        struct Node* curr = temp.node;
        int hd = temp.hd;

        map[hd * 2 + mapCount[hd]] = curr;
        mapCount[hd]++;

        if (curr->left)
        {
            enqueue(curr->left, hd - 1);
        }

        if (curr->right)
        {
            enqueue(curr->right, hd + 1);
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        if (mapCount[i] > 0)
        {
            printf("[");
            for (int j = 0; j < mapCount[i]; j++)
            {
                printf("%d", map[i * 2 + j]->data);
                if (j < mapCount[i] - 1)
                {
                    printf(",");
                }
            }
            printf("] ");
        }
    }
}

int main()
{
    struct Node* root = create(3);
    root->left = create(9);
    root->right = create(20);
    root->right->left = create(15);
    root->right->right = create(7);

    printf("Vertical Order Traversal: ");
    vertical(root);  
    printf("\n");

    return 0;
}
