#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char words[1000][50];
int visited[1000];
int n;

int differByOne(char *a, char *b) {
    int diff = 0;
    for (int i = 0; a[i] && b[i]; i++)
        if (a[i] != b[i])
            diff++;
    return diff == 1;
}

int bfs(char *begin, char *end) {
    int queue[1000], dist[1000], front = 0, rear = 0;
    queue[rear] = -1;
    dist[rear++] = 1;
    char cur[50];
    strcpy(cur, begin);
    while (front < rear) {
        int idx = queue[front];
        int d = dist[front];
        front++;
        if (idx == -1)
            strcpy(cur, begin);
        else
            strcpy(cur, words[idx]);
        if (strcmp(cur, end) == 0)
            return d;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && differByOne(cur, words[i])) {
                visited[i] = 1;
                queue[rear] = i;
                dist[rear++] = d + 1;
            }
        }
    }
    return 0;
}

int main() {
    char begin[50], end[50];
    printf("Enter begin word: ");
    scanf("%s", begin);
    printf("Enter end word: ");
    scanf("%s", end);
    printf("Enter number of words in dictionary: ");
    scanf("%d", &n);
    printf("Enter words:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
        visited[i] = 0;
    }
    int found = 0;
    for (int i = 0; i < n; i++)
        if (strcmp(words[i], end) == 0)
            found = 1;
    if (!found) {
        printf("0\n");
        return 0;
    }
    printf("%d\n", bfs(begin, end));
    return 0;
}
