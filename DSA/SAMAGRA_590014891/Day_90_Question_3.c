#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100
#define LEN 20

char wordList[MAX][LEN];
bool visited[MAX];
int N;

bool differByOne(char *a, char *b) {
    int diff = 0;
    for (int i = 0; a[i] && b[i]; i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return false;
    }
    return diff == 1;
}

int bfs(char begin[], char end[]) {
    int queue[MAX], dist[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < N; i++) visited[i] = false, dist[i] = 0;

    for (int i = 0; i < N; i++) {
        if (differByOne(begin, wordList[i])) {
            queue[rear++] = i;
            visited[i] = true;
            dist[i] = 2;
        }
    }

    while (front < rear) {
        int idx = queue[front++];
        if (strcmp(wordList[idx], end) == 0) return dist[idx];
        for (int j = 0; j < N; j++) {
            if (!visited[j] && differByOne(wordList[idx], wordList[j])) {
                queue[rear++] = j;
                visited[j] = true;
                dist[j] = dist[idx] + 1;
            }
        }
    }
    return 0;
}

int main() {
    char begin[LEN], end[LEN];
    scanf("%s %s", begin, end);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%s", wordList[i]);

    int res = bfs(begin, end);
    printf("%d\n", res);
    return 0;
}
