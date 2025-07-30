#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Simple stack for integers
typedef struct IntNode {
    int data;
    struct IntNode* next;
} IntNode;

typedef struct IntStack {
    IntNode* top;
} IntStack;

void intPush(IntStack* s, int data) {
    IntNode* newNode = (IntNode*)malloc(sizeof(IntNode));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int intPop(IntStack* s) {
    if (s->top == NULL) {
        return -1;
    }
    IntNode* temp = s->top;
    int data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}

// Simple stack for strings (char pointers)
typedef struct StringNode {
    char* data;
    struct StringNode* next;
} StringNode;

typedef struct StringStack {
    StringNode* top;
} StringStack;

void stringPush(StringStack* s, char* data) {
    StringNode* newNode = (StringNode*)malloc(sizeof(StringNode));
    newNode->data = strdup(data);
    newNode->next = s->top;
    s->top = newNode;
}

char* stringPop(StringStack* s) {
    if (s->top == NULL) {
        return NULL;
    }
    StringNode* temp = s->top;
    char* data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}

int main() {
    char s[1000];
    scanf("%s", s);

    IntStack* numStack = (IntStack*)malloc(sizeof(IntStack));
    numStack->top = NULL;

    StringStack* strStack = (StringStack*)malloc(sizeof(StringStack));
    strStack->top = NULL;

    char* currentString = (char*)malloc(1000 * sizeof(char));
    currentString[0] = '\0';

    int i = 0;
    while (i < strlen(s)) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            intPush(numStack, num);
        } else if (s[i] == '[') {
            stringPush(strStack, currentString);
            currentString[0] = '\0';
            i++;
        } else if (s[i] == ']') {
            int repeatTimes = intPop(numStack);
            char* prevString = stringPop(strStack);
            char* temp = (char*)malloc(1000 * sizeof(char));
            temp[0] = '\0';
            for (int k = 0; k < repeatTimes; k++) {
                strcat(temp, currentString);
            }
            strcpy(currentString, prevString);
            strcat(currentString, temp);
            free(prevString);
            free(temp);
            i++;
        } else {
            char charToStr[2];
            charToStr[0] = s[i];
            charToStr[1] = '\0';
            strcat(currentString, charToStr);
            i++;
        }
    }

    printf("%s\n", currentString);

    free(currentString);

    while (numStack->top != NULL) {
        intPop(numStack);
    }
    free(numStack);

    while (strStack->top != NULL) {
        char* temp = stringPop(strStack);
        free(temp);
    }
    free(strStack);

    return 0;
}
