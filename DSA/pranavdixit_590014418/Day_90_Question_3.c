#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define MAX 50
#define WORDLEN 10

char dict[MAX][WORDLEN];
int dictSize;

int differByOne(char* a, char* b) {
    int diff = 0;
    for (int i = 0; a[i] && b[i]; i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return 0;
    }
    return diff == 1;
}

int bfs(char* begin, char* end) {
    int visited[MAX] = {0};
    char queue[MAX][WORDLEN];
    int dist[MAX];
    int front = 0, rear = 0;

    strcpy(queue[rear], begin);
    dist[rear++] = 1;

    while (front < rear) {
        char word[WORDLEN];
        strcpy(word, queue[front]);
        int d = dist[front];
        front++;

        if (strcmp(word, end) == 0) return d;

        for (int i = 0; i < dictSize; i++) {
            if (!visited[i] && differByOne(word, dict[i])) {
                visited[i] = 1;
                strcpy(queue[rear], dict[i]);
                dist[rear++] = d + 1;
            }
        }
    }
    return 0;
}

int main() {
    char begin[] = "hit";
    char end[] = "cog";
    char words[][WORDLEN] = {"hot","dot","dog","lot","log","cog"};
    dictSize = 6;
    for (int i = 0; i < dictSize; i++) strcpy(dict[i], words[i]);

    int ans = bfs(begin, end);
    printf("%d\n", ans);
    return 0;
}
