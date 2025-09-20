<h2 align="center">Day 97 (20/09/2025)</h2>

## 1. Palindrome Partitioning (Min Cuts)
A problem that demonstrates string partitioning optimization and teaches interval-based dynamic programming using palindrome verification for efficient substring division and minimal cut operations.

Given a **string**, find the **minimum number of cuts** needed to partition it into palindromic substrings using DP strategy. This operation is fundamental in **string processing** and **optimization problems** where you need to **minimize partition operations** while satisfying palindrome constraints efficiently. The technique uses **2D DP for palindrome detection** combined with **1D DP for minimum cuts**, where cuts[i] represents minimum cuts needed for substring[0...i]. This concept is essential in **text analysis**, **DNA sequencing**, and **pattern recognition** where palindromic partitioning enables efficient string decomposition and optimal structure-based analysis in sequence processing systems.

This demonstrates **interval DP** and **string optimization techniques** that are crucial for **palindrome partitioning and efficient substring division operations**.

**Your task:** Implement dynamic programming to find minimum cuts for palindromic partitioning using palindrome precomputation and cut optimization.

### Examples

**Input:**
```
String: "aab"

Step 1: Palindrome Detection Table
    0  1  2  (indices)
    a  a  b  (characters)
0a  T  T  F  
1a  ·  T  F  
2b  ·  ·  T  

Palindrome analysis:
- "a" at [0,0]: True (single char)
- "a" at [1,1]: True (single char)  
- "b" at [2,2]: True (single char)
- "aa" at [0,1]: True (s[0]==s[1])
- "ab" at [1,2]: False (s[1]!=s[2])
- "aab" at [0,2]: False (s[0]!=s[2])

Step 2: Minimum Cuts DP
cuts[0] = 0 (single char "a" - no cuts needed)
cuts[1] = 0 (substring "aa" is palindrome - no cuts needed)
cuts[2] = min(cuts[1]+1, cuts[0]+1) where cut creates palindromes
        = min(0+1, invalid) = 1

Optimal partitioning:
"aab" → "aa" | "b" (1 cut)

Visual representation:
String: a a b
Parts:  [aa] [b]
Cuts:   1 cut between "aa" and "b"
```
**Output:**
```
1
```

---

**Input:**
```
String: "a"

Palindrome Detection:
Single character is always a palindrome.

Minimum Cuts Analysis:
cuts[0] = 0 (no cuts needed for single palindrome)

Optimal partitioning:
"a" → ["a"] (0 cuts - already palindrome)

Visual representation:
String: a
Parts:  [a]  
Cuts:   0 cuts needed
```
**Output:**
```
0
```

---

## 2. Longest Palindromic Subsequence
A problem that introduces palindrome optimization and teaches subsequence-based dynamic programming using character matching strategy for efficient palindromic pattern detection and maximum length operations.

Given a **string**, find the **length of longest palindromic subsequence** using DP strategy. This operation is fundamental in **sequence analysis** and **pattern matching** where you need to **find maximum palindromic structure** within sequences efficiently. The technique uses **2D DP** where dp[i][j] represents LPS length in substring[i...j], with recurrence based on character matching at endpoints. This concept is essential in **DNA analysis**, **text processing**, and **bioinformatics** where palindromic sequences enable efficient genetic pattern identification and optimal structure-based analysis in biological sequence systems.

This introduces **palindrome DP** and **subsequence optimization techniques** that are essential for **palindromic pattern detection and efficient sequence structure analysis operations**.

**Your task:** Implement 2D dynamic programming to find longest palindromic subsequence using interval-based character matching.

### Examples

**Input:**
```
String: "bbbab"

2D DP Table Construction:
Substring intervals (i,j) where i≤j:
    0  1  2  3  4  (indices)
    b  b  b  a  b  (characters)

    0  1  2  3  4
0b  1  2  3  3  4  
1b  ·  1  2  2  3
2b  ·  ·  1  1  3  
3a  ·  ·  ·  1  1
4b  ·  ·  ·  ·  1

Step-by-step calculation:
- Single chars: dp[i][i] = 1 (diagonal)
- dp[0][1]: s[0]==s[1] → 1+dp[1][0] = 1+0 = 2 → "bb"
- dp[0][2]: s[0]==s[2] → 1+dp[1][1] = 1+1 = 2 → "bb" 
- dp[1][2]: s[1]==s[2] → 1+dp[2][1] = 1+0 = 2 → "bb"
- dp[0][4]: s[0]==s[4] → 1+dp[1][3] = 1+2 = 4 → "bbbb"

Optimal LPS reconstruction:
Characters: b b b a b
Indices:    0 1 2 3 4
Selected:   ✓ ✓ ✓ ✗ ✓  → "bbbb"

LPS: "bbbb" with length 4
```
**Output:**
```
4
```

---

**Input:**
```
String: "cbbd"

2D DP Table Construction:
    0  1  2  3  (indices)  
    c  b  b  d  (characters)

    0  1  2  3
0c  1  1  2  2
1b  ·  1  2  2  
2b  ·  ·  1  1
3d  ·  ·  ·  1

Key calculations:
- dp[1][2]: s[1]==s[2] → 1+dp[2][1] = 1+0 = 2 → "bb"
- dp[0][2]: s[0]≠s[2] → max(dp[0][1],dp[1][2]) = max(1,2) = 2
- dp[0][3]: s[0]≠s[3] → max(dp[0][2],dp[1][3]) = max(2,2) = 2

Optimal LPS reconstruction:
Characters: c b b d
Indices:    0 1 2 3  
Selected:   ✗ ✓ ✓ ✗  → "bb"

LPS: "bb" with length 2
```
**Output:**
```
2
```

---

## 3. Matrix Chain Multiplication
A problem that teaches optimization ordering and demonstrates interval-based dynamic programming using cost minimization strategy for efficient multiplication sequencing and optimal parenthesization operations.

Given **matrix dimensions array**, find the **minimum scalar multiplications** needed to multiply the matrix chain using optimal parenthesization DP strategy. This operation is fundamental in **computational optimization** and **algorithm efficiency** where you need to **minimize multiplication operations** through optimal grouping efficiently. The technique uses **interval DP** where dp[i][j] represents minimum cost to multiply matrices from i to j, considering all possible split points. This concept is essential in **numerical computing**, **graphics processing**, and **scientific calculations** where operation minimization enables efficient computation and optimal resource utilization in mathematical processing systems.

This teaches **interval optimization DP** and **cost minimization techniques** that are crucial for **operation sequencing and efficient computational optimization operations**.

**Your task:** Implement interval dynamic programming to find optimal matrix multiplication order minimizing scalar operations.

### Examples

**Input:**
```
Matrix dimensions: [1,2,3,4]
Matrices: A₁(1×2), A₂(2×3), A₃(3×4)

3D DP Analysis - Chain length vs Cost:
Length 1: dp[1][1]=0, dp[2][2]=0, dp[3][3]=0 (single matrices)

Length 2: 
- dp[1][2]: A₁×A₂ = (1×2×3) = 6 operations
- dp[2][3]: A₂×A₃ = (2×3×4) = 24 operations

Length 3:
- dp[1][3]: Split at k=1: dp[1][1] + dp[2][3] + (1×2×4) = 0+24+8 = 32
           Split at k=2: dp[1][2] + dp[3][3] + (1×3×4) = 6+0+12 = 18
           Choose minimum: 18

Optimal parenthesization analysis:
Option 1: (A₁×A₂)×A₃ = 6 + 1×3×4 = 6 + 12 = 18 ✓
Option 2: A₁×(A₂×A₃) = 24 + 1×2×4 = 24 + 8 = 32

Visual representation:
Matrices: [1×2] [2×3] [3×4]
Grouping: ([1×2][2×3]) [3×4]
Step 1:   A₁×A₂ → [1×3] (cost: 1×2×3 = 6)  
Step 2:   [1×3]×A₃ → [1×4] (cost: 1×3×4 = 12)
Total cost: 6 + 12 = 18
```
**Output:**
```
18
```

---

**Input:**
```
Matrix dimensions: [10,20,30]  
Matrices: A₁(10×20), A₂(20×30)

Single multiplication case:
Only one way to multiply: A₁ × A₂
Cost = 10 × 20 × 30 = 6000 operations

DP Analysis:
Length 1: dp[1][1] = 0, dp[2][2] = 0
Length 2: dp[1][2] = 10×20×30 = 6000

No optimization possible with only 2 matrices.

Visual representation:
Matrices: [10×20] [20×30]
Operation: A₁ × A₂ = [10×30]
Cost: 10 × 20 × 30 = 6000 scalar multiplications
```
**Output:**
```
6000
```
