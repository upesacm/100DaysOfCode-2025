#include <stdio.h>

#define MAX 100

int stack[MAX], temp[MAX], top = -1, ttop = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }
int peek() { return stack[top]; }
int isEmpty() { return top == -1; }

void tpush(int x) { temp[++ttop] = x; }
int tpop() { return temp[ttop--]; }
int tpeek() { return temp[ttop]; }
int tisEmpty() { return ttop == -1; }

int main()
{
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (top to bottom): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    while (!isEmpty())
    {
        int t = pop();
        while (!tisEmpty() && tpeek() > t)
            push(tpop());
        tpush(t);
    }

    printf("Sorted stack (top to bottom): ");
    while (!tisEmpty())
        printf("%d ", tpop());
    printf("\n");

    return 0;
}
