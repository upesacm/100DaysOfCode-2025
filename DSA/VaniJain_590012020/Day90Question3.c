#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
#define WORD_LEN 20
typedef struct 
{
    int wordIndex;
    int level;
} QueueNode;
int wordDiffOne(const char* a, const char* b) 
{
    int diff = 0;
    for (int i = 0; a[i]; i++) 
    {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return 0;
    }
    return diff == 1;
}
int wordLadderLength(char words[][WORD_LEN], int n, char* beginWord, char* endWord) 
{
    int visited[MAX] = {0};
    QueueNode queue[MAX];
    int front = 0, rear = 0;
    int beginIndex = -1;
    for (int i = 0; i < n; i++)
        if (strcmp(words[i], beginWord) == 0)
            beginIndex = i;
    if (beginIndex == -1) 
    {
        strcpy(words[n], beginWord);
        beginIndex = n;
        n++;
    }
    queue[rear++] = (QueueNode){beginIndex, 1};
    visited[beginIndex] = 1;
    while (front < rear) 
    {
        QueueNode node = queue[front++];
        int idx = node.wordIndex;
        int level = node.level;
        if (strcmp(words[idx], endWord) == 0) return level;
        for (int i = 0; i < n; i++) 
        {
            if (!visited[i] && wordDiffOne(words[idx], words[i])) 
            {
                visited[i] = 1;
                queue[rear++] = (QueueNode){i, level + 1};
            }
        }
    }
    return 0; 
}
int main() 
{
    int n;
    char beginWord[WORD_LEN], endWord[WORD_LEN];
    char words[MAX][WORD_LEN];
    printf("Enter begin word: ");
    scanf("%s", beginWord);
    printf("Enter end word: ");
    scanf("%s", endWord);
    printf("Enter number of words in dictionary: ");
    scanf("%d", &n);
    printf("Enter words:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", words[i]);
    }
    int len = wordLadderLength(words, n, beginWord, endWord);
    if (len)
        printf("Shortest transformation length = %d\n", len);
    else
        printf("No transformation sequence exists.\n");
    return 0;
}
