#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100
#define WORDLEN 20

typedef struct {
    char word[WORDLEN];
    int dist;
} Node;

bool oneCharDiff(char* a, char* b) {
    int diff = 0;
    for (int i = 0; a[i] && b[i]; i++)
        if (a[i] != b[i] && ++diff > 1) return false;
    return diff == 1;
}

int wordLadder(char* begin, char* end, char wordList[][WORDLEN], int n) {
    bool visited[MAX] = {false};
    Node queue[MAX];
    int front = 0, rear = 0;

    strcpy(queue[rear].word, begin);
    queue[rear].dist = 1;
    rear++;

    while (front < rear) {
        Node cur = queue[front++];
        if (strcmp(cur.word, end) == 0) return cur.dist;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && oneCharDiff(cur.word, wordList[i])) {
                visited[i] = true;
                strcpy(queue[rear].word, wordList[i]);
                queue[rear].dist = cur.dist + 1;
                rear++;
            }
        }
    }
    return 0; // No transformation found
}

int main() {
    char wordList[][WORDLEN] = {"hot","dot","dog","lot","log","cog"};
    int n = 6;
    char begin[] = "hit";
    char end[] = "cog";

    int ans = wordLadder(begin, end, wordList, n);
    printf("Shortest Transformation Length = %d\n", ans);
    return 0;
}

