#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool differByOne(char* a, char* b) {
    int diff = 0;
    for (int i = 0; a[i]; i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return false;
    }
    return diff == 1;
}

int wordLadderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    bool* visited = calloc(wordListSize, sizeof(bool));
    char** queue = malloc(wordListSize * sizeof(char*));
    int* dist = malloc(wordListSize * sizeof(int));
    int front = 0, rear = 0;

    // enqueue beginWord
    queue[rear] = beginWord;
    dist[rear++] = 1;

    while (front < rear) {
        char* cur = queue[front];
        int d = dist[front++];
        if (strcmp(cur, endWord) == 0) {
            free(visited); free(queue); free(dist);
            return d;
        }

        for (int i = 0; i < wordListSize; i++) {
            if (!visited[i] && differByOne(cur, wordList[i])) {
                visited[i] = true;
                queue[rear] = wordList[i];
                dist[rear++] = d + 1;
            }
        }
    }
    free(visited); free(queue); free(dist);
    return 0;
}
