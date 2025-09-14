#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    char** words;
    int* distances;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->words = (char**)malloc(capacity * sizeof(char*));
    queue->distances = (int*)malloc(capacity * sizeof(int));
    for (int i = 0; i < capacity; i++) {
        queue->words[i] = (char*)malloc(100 * sizeof(char));
    }
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void enqueue(struct Queue* queue, char* word, int distance) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    strcpy(queue->words[queue->rear], word);
    queue->distances[queue->rear] = distance;
    queue->size++;
}

void dequeue(struct Queue* queue, char* word, int* distance) {
    strcpy(word, queue->words[queue->front]);
    *distance = queue->distances[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
}

int canTransform(char* word1, char* word2, int len) {
    int diff = 0;
    for (int i = 0; i < len; i++) {
        if (word1[i] != word2[i]) diff++;
        if (diff > 1) return 0;
    }
    return diff == 1;
}

int wordLadder(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int* visited = (int*)calloc(wordListSize, sizeof(int));
    struct Queue* queue = createQueue(wordListSize + 1);
    
    enqueue(queue, beginWord, 1);
    
    while (!isQueueEmpty(queue)) {
        char currentWord[100];
        int distance;
        dequeue(queue, currentWord, &distance);
        
        if (strcmp(currentWord, endWord) == 0) {
            free(visited);
            for (int i = 0; i < queue->capacity; i++) {
                free(queue->words[i]);
            }
            free(queue->words);
            free(queue->distances);
            free(queue);
            return distance;
        }
        
        for (int i = 0; i < wordListSize; i++) {
            if (!visited[i] && canTransform(currentWord, wordList[i], strlen(currentWord))) {
                visited[i] = 1;
                enqueue(queue, wordList[i], distance + 1);
            }
        }
    }
    
    free(visited);
    for (int i = 0; i < queue->capacity; i++) {
        free(queue->words[i]);
    }
    free(queue->words);
    free(queue->distances);
    free(queue);
    return 0;
}

int main() {
    char beginWord[100], endWord[100];
    printf("Enter begin word: ");
    scanf("%s", beginWord);
    printf("Enter end word: ");
    scanf("%s", endWord);
    
    int wordListSize;
    printf("Enter size of word list: ");
    scanf("%d", &wordListSize);
    
    char** wordList = (char**)malloc(wordListSize * sizeof(char*));
    for (int i = 0; i < wordListSize; i++) {
        wordList[i] = (char*)malloc(100 * sizeof(char));
    }
    
    printf("Enter %d words in the word list:\n", wordListSize);
    for (int i = 0; i < wordListSize; i++) {
        scanf("%s", wordList[i]);
    }
    
    int result = wordLadder(beginWord, endWord, wordList, wordListSize);
    printf("%d\n", result);
    
    for (int i = 0; i < wordListSize; i++) {
        free(wordList[i]);
    }
    free(wordList);
    return 0;
}
