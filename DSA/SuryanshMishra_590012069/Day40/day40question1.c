// 1. Celebrity Problem
// A problem that demonstrates graph theory applications and teaches efficient candidate elimination techniques using stack-based algorithms for social network analysis and relationship mapping.

// In a party of n people, find the celebrity using a stack-based approach. A celebrity is known by everyone but knows no one. This operation is fundamental in graph theory and social network analysis where you need to identify central nodes with specific connectivity properties. The technique uses systematic elimination through stack operations to reduce the search space from O(n²) to O(n) time complexity. Understanding this concept is crucial for influence analysis, network topology problems, and graph traversal optimization where identifying nodes with unique properties requires efficient filtering algorithms.

// This teaches graph-based elimination algorithms and social network analysis techniques that are essential for relationship mapping and efficient node identification in complex network structures.

// Your task: Use stack-based candidate elimination to efficiently identify the celebrity by systematically reducing potential candidates through relationship queries.

// Examples
// Input:

// Matrix for 3 people
// 0 1 1
// 0 0 1
// 0 0 0
// Output:

// 2
// Input:

// 0 1
// 1 0
// Output:

// -1
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int M[MAX][MAX];
int knows(int a, int b) {
return M[a][b];
}
int findCelebrity(int n) {
int stack[MAX];
int top = -1;
for (int i = 0; i < n; i++) {
stack[++top] = i;
}
while (top >= 1) {
int a = stack[top--];
int b = stack[top--];
if (knows(a, b)) {
stack[++top] = b;
} else {
stack[++top] = a;
}
}
if (top == -1) return -1; 
int candidate = stack[top];
for (int i = 0; i < n; i++) {
if (i != candidate) {
if (knows(candidate, i) || !knows(i, candidate)) {
return -1;
}
}
}
return candidate;
}