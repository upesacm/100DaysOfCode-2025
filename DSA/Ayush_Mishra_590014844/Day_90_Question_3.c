#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int differByOne(char *a, char *b) {
    int diff = 0;
    for (int i = 0; a[i]; i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return 0;
    }
    return diff == 1;
}

int bfs(char **words, int wordCount, char *begin, char *end) {
    int *visited = (int *)calloc(wordCount, sizeof(int));
    char **queue = (char **)malloc(wordCount * sizeof(char *));
    int *depth = (int *)malloc(wordCount * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < wordCount; i++) {
        if (differByOne(begin, words[i])) {
            queue[rear] = words[i];
            depth[rear++] = 2;
            visited[i] = 1;
        }
    }
    while (front < rear) {
        char *curr = queue[front];
        int d = depth[front++];
        if (strcmp(curr, end) == 0) {
            free(visited);
            free(queue);
            free(depth);
            return d;
        }
        for (int i = 0; i < wordCount; i++) {
            if (!visited[i] && differByOne(curr, words[i])) {
                queue[rear] = words[i];
                depth[rear++] = d + 1;
                visited[i] = 1;
            }
        }
    }
    free(visited);
    free(queue);
    free(depth);
    return 0;
}

int main() {
    char begin[20], end[20];
    int n;
    scanf("%s %s %d", begin, end, &n);
    char **words = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        words[i] = (char *)malloc(20 * sizeof(char));
        scanf("%s", words[i]);
    }
    int result = bfs(words, n, begin, end);
    printf("%d\n", result);
    for (int i = 0; i < n; i++) free(words[i]);
    free(words);
    return 0;
}
