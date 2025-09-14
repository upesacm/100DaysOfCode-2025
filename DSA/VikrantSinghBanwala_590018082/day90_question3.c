#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000
#define WORDLEN 20

struct Node {
    char word[WORDLEN];
    int level;
};

bool isAdjacent(char* a, char* b) {
    int count = 0;
    for (int i = 0; a[i] && b[i]; i++) {
        if (a[i] != b[i]) count++;
        if (count > 1) return false;
    }
    return count == 1;
}

int wordLadder(char* begin, char* end, char dict[MAX][WORDLEN], int n) {
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    struct Node queue[MAX];
    int front = 0, rear = 0;

    strcpy(queue[rear].word, begin);
    queue[rear++].level = 1;

    while (front < rear) {
        struct Node curr = queue[front++];
        if (strcmp(curr.word, end) == 0)
            return curr.level;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && isAdjacent(curr.word, dict[i])) {
                visited[i] = true;
                strcpy(queue[rear].word, dict[i]);
                queue[rear++].level = curr.level + 1;
            }
        }
    }
    return 0; // no transformation
}

int main() {
    char dict[MAX][WORDLEN] = {"hot","dot","dog","lot","log","cog"};
    int n = 6;

    char begin[] = "hit";
    char end[] = "cog";

    printf("%d\n", wordLadder(begin, end, dict, n)); // Output: 5
    return 0;
}