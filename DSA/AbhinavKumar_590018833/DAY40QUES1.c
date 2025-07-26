// 1. Celebrity Problem
// A problem that demonstrates graph theory applications and teaches efficient candidate elimination techniques
//  using stack-based algorithms for social network analysis and relationship mapping.

// In a party of n people, find the celebrity using a stack-based approach. A celebrity is known by everyone but
//  knows no one. This operation is fundamental in graph theory and social network analysis where you need to 
// identify central nodes with specific connectivity properties. The technique uses systematic elimination
//  through stack operations to reduce the search space from O(n²) to O(n) time complexity. 

// Understanding this concept is crucial for influence analysis, network topology problems, and graph traversal 
// optimization where identifying nodes with unique properties requires efficient filtering algorithms.

// This teaches graph-based elimination algorithms and social network analysis techniques that are essential for
//  relationship mapping and efficient node identification in complex network structures.

// Your task: Use stack-based candidate elimination to efficiently identify the celebrity by systematically reducing
//  potential candidates through relationship queries.

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

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool knows(int *M,int a,int b,int n){
    return *((M+a*n)+b);
}

int findCelibrity(int *M,int n){
    if(n<=0) return -1;
    int candidte=0;
    for(int i=0;i<n;i++){
        
        if(knows(M,candidte,i,n)) candidte=i;
    }
    for(int i=0;i<n;i++){
        if(i!=candidte){
            if(knows(M,candidte,i,n)||!knows(M,i,candidte,n)) return -1;
        }
    }    
    return candidte;
    

}
int main(){
    int M1[3][3]={
        {0,1,1},
        {0,0,1},
        {0,0,0}
    };
    int n1=3;
    printf("Output: %d\n\n",findCelibrity((int*)M1,n1));
    int M2[2][2] = {
        {0, 1},
        {1, 0}
    };
    int n2 = 2;
    printf("Output: %d\n\n", findCelibrity((int *)M2, n2));
    
    return 0;
}
