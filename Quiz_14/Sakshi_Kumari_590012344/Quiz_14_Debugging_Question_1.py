1. Identify the specific indexing bug
Used text1[i] and text2[j] instead of text1[i-1] and text2[j-1].

2. Why this causes incorrect character comparison: 
Because the DP table uses 1-based indexing (extra row/col for base case), but the strings use 0-based indexing. 
This mismatch shifts character comparisons by one, leading to wrong results.
