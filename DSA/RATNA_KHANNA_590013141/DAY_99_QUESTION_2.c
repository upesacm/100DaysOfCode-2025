#include <stdio.h>
#include <limits.h>

#define MAXN 1000

typedef struct {
    int data[MAXN];
    int max[MAXN];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    int m = val;
    if (!empty(s) && s->max[s->top] > m) m = s->max[s->top];
    s->data[++s->top] = val;
    s->max[s->top] = m;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int getMax(Stack *s) {
    return s->max[s->top];
}

// Queue with max using 2 stacks
typedef struct {
    Stack in, out;
} MaxQueue;

void mqInit(MaxQueue *q) {
    init(&q->in);
    init(&q->out);
}

void mqPush(MaxQueue *q, int val) {
    push(&q->in, val);
}

void mqPop(MaxQueue *q) {
    if (empty(&q->out)) {
        while (!empty(&q->in)) {
            int v = pop(&q->in);
            int m = v;
            if (!empty(&q->out) && getMax(&q->out) > m) m = getMax(&q->out);
            q->out.data[++q->out.top] = v;
            q->out.max[q->out.top] = m;
        }
    }
    if (!empty(&q->out)) pop(&q->out);
}

int mqMax(MaxQueue *q) {
    if (empty(&q->in)) return getMax(&q->out);
    if (empty(&q->out)) return getMax(&q->in);
    int m1 = getMax(&q->in);
    int m2 = getMax(&q->out);
    return m1 > m2 ? m1 : m2;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    MaxQueue q;
    mqInit(&q);

    for (int i = 0; i < n; i++) {
        mqPush(&q, arr[i]);
        if (i >= k - 1) {
            printf("%d ", mqMax(&q));
            mqPop(&q);
        }
    }
    printf("\n");
    return 0;
}
