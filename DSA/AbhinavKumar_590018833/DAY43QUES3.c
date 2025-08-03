// 3. Check if a Queue is Palindrome
// A problem that teaches symmetry detection algorithms and demonstrates combined queue-stack operations for sequence analysis using complementary data structure properties for pattern recognition.

// Given a queue of characters, determine whether the sequence forms a palindrome using only queue and stack operations. This operation requires understanding symmetry analysis where you need to compare sequence elements from both ends using the complementary properties of FIFO and LIFO structures. The technique is fundamental in pattern recognition and string analysis where you need to detect symmetric properties efficiently. Understanding this concept is crucial for data validation, sequence verification, and structural analysis where palindrome detection indicates special mathematical or linguistic properties.

// This teaches symmetry detection algorithms and dual data structure techniques that are essential for pattern recognition and efficient sequence symmetry analysis operations.

// Your task: Use complementary queue and stack operations to systematically compare sequence elements for palindrome detection through structural symmetry analysis.

// Examples
// Input:

// ['r', 'a', 'c', 'e', 'c', 'a', 'r']
// Output:

// Yes
// Input:

// ['a', 'b', 'c']
// Output:


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>



typedef struct {
    char* items;
    int front, rear, size, capacity;
} CharQueue;

CharQueue* createCharQueue(int capacity) {
    CharQueue* q = (CharQueue*)malloc(sizeof(CharQueue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->items = (char*)malloc(q->capacity * sizeof(char));
    return q;
}
bool isQueueEmpty(CharQueue* q) { return (q->size == 0); }
void enqueue(CharQueue* q, char item) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = item;
    q->size++;
}
char dequeue(CharQueue* q) {
    if (isQueueEmpty(q)) return '\0';
    char item = q->items[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

typedef struct {
    char* items;
    int top;
    int capacity;
} CharStack;

CharStack* createCharStack(int capacity) {
    CharStack* s = (CharStack*)malloc(sizeof(CharStack));
    s->capacity = capacity;
    s->top = -1;
    s->items = (char*)malloc(s->capacity * sizeof(char));
    return s;
}
bool isStackEmpty(CharStack* s) { return (s->top == -1); }
void push(CharStack* s, char item) {
    if (s->top == s->capacity - 1) return;
    s->items[++(s->top)] = item;
}
char pop(CharStack* s) {
    if (isStackEmpty(s)) return '\0';
    return s->items[(s->top)--];
}


bool isPalindrome(char* str) {
    int len = strlen(str);
    CharQueue* q = createCharQueue(len);
    CharStack* s = createCharStack(len);

    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) { 
            char lower_char = tolower(str[i]);
            enqueue(q, lower_char);
            push(s, lower_char);
        }
    }

    bool palindrome = true;
    while (!isQueueEmpty(q)) {
        if (dequeue(q) != pop(s)) {
            palindrome = false;
            break;
        }
    }

    free(q->items);
    free(q);
    free(s->items);
    free(s);

    return palindrome;
}

int main() {
    char str1[] = "A man, a plan, a canal: Panama";
    char str2[] = "racecar";
    char str3[] = "hello";

    printf("\"%s\" is a palindrome? %s\n", str1, isPalindrome(str1) ? "Yes" : "No");
    printf("\"%s\" is a palindrome? %s\n", str2, isPalindrome(str2) ? "Yes" : "No");
    printf("\"%s\" is a palindrome? %s\n", str3, isPalindrome(str3) ? "Yes" : "No");

    return 0;
}