<h2 align="center">Day 94 (17/09/2025)</h2>

## 1. Longest Increasing Subsequence (LIS)
A problem that demonstrates sequence optimization and teaches subsequence analysis dynamic programming using length maximization strategy for efficient pattern detection and optimal ordering identification operations.

Given an **integer array**, find the **length of longest strictly increasing subsequence** using DP strategy. This operation is fundamental in **sequence analysis** and **pattern recognition** where you need to **identify optimal increasing trends** for data analysis efficiently. The technique uses **DP with binary search optimization** where each position tracks longest increasing subsequence ending at that index, or uses patience sorting approach for O(n log n) complexity. This concept is essential in **stock analysis**, **scheduling optimization**, and **data mining** where finding increasing patterns enables efficient trend identification and optimal sequence-based analysis in ordered data systems.

This demonstrates **sequence DP algorithms** and **optimization techniques** that are crucial for **pattern detection and efficient subsequence analysis operations**.

**Your task:** Implement dynamic programming to find longest increasing subsequence length using either O(n²) or O(n log n) approach.

### Examples

**Input:**
```
Array: [10, 9, 2, 5, 3, 7, 101, 18]

DP Analysis (O(n²) approach):
Index 0 (10): LIS length = 1, LIS = [10]
Index 1 (9):  LIS length = 1, LIS = [9] (9 < 10, can't extend)
Index 2 (2):  LIS length = 1, LIS = [2] (2 < all previous)
Index 3 (5):  LIS length = 2, LIS = [2, 5] (extends from index 2)
Index 4 (3):  LIS length = 2, LIS = [2, 3] (extends from index 2)
Index 5 (7):  LIS length = 3, LIS = [2, 3, 7] or [2, 5, 7]
Index 6 (101): LIS length = 4, LIS = [2, 3, 7, 101]
Index 7 (18):  LIS length = 4, LIS = [2, 3, 7, 18]

Visual representation:
[10, 9, 2, 5, 3, 7, 101, 18]
      ✓  ✓  ✗  ✓   ✓    ✗   → LIS = [2, 3, 7, 101]
      ✓  ✓     ✓   ✓         → Alternative = [2, 5, 7, 101]

DP Array: [1, 1, 1, 2, 2, 3, 4, 4]
Maximum LIS length: 4
```
**Output:**
```
4
```

---

**Input:**
```
Array: [0, 1, 0, 3, 2, 3]

DP Analysis:
Index 0 (0): LIS length = 1, LIS = [0]
Index 1 (1): LIS length = 2, LIS = [0, 1]
Index 2 (0): LIS length = 1, LIS = [0] (can't extend any)
Index 3 (3): LIS length = 3, LIS = [0, 1, 3]
Index 4 (2): LIS length = 3, LIS = [0, 1, 2]
Index 5 (3): LIS length = 4, LIS = [0, 1, 2, 3]

Visual representation:
[0, 1, 0, 3, 2, 3]
 ✓  ✓  ✗  ✗  ✓  ✓  → LIS = [0, 1, 2, 3]

DP Array: [1, 2, 1, 3, 3, 4]
Maximum LIS length: 4
```
**Output:**
```
4
```

---

## 2. Longest Common Subsequence (LCS)
A problem that introduces string matching optimization and teaches two-sequence dynamic programming using character alignment strategy for efficient similarity detection and optimal common pattern identification operations.

Given **two strings**, find the **length of longest common subsequence** using 2D DP strategy. This operation is fundamental in **text comparison** and **sequence alignment** where you need to **find maximum matching characters** preserving order efficiently. The technique uses **2D DP table** where dp[i][j] represents LCS length for first i characters of string1 and first j characters of string2. This concept is essential in **DNA sequencing**, **plagiarism detection**, and **version control** where finding common subsequences enables efficient similarity analysis and optimal alignment-based comparison in string processing systems.

This introduces **2D DP algorithms** and **string matching techniques** that are essential for **sequence alignment and efficient similarity detection operations**.

**Your task:** Implement 2D dynamic programming to find longest common subsequence length between two input strings.

### Examples

**Input:**
```
String1: "abcde"
String2: "ace"

2D DP Table Construction:
    ""  a  c  e
""   0  0  0  0
a    0  1  1  1  (match 'a')
b    0  1  1  1  (no new matches)
c    0  1  2  2  (match 'c')
d    0  1  2  2  (no new matches)
e    0  1  2  3  (match 'e')

LCS Reconstruction:
Step back through table:
- dp[5][3] = 3, came from dp[4][2] (matched 'e')
- dp[4][2] = 2, came from dp[2][1] (matched 'c')  
- dp[2][1] = 1, came from dp[0][0] (matched 'a')

Visual alignment:
String1: a b c d e
String2: a   c   e
LCS:     a   c   e

LCS = "ace", length = 3
```
**Output:**
```
3
```

---

**Input:**
```
String1: "abc"
String2: "abc"

2D DP Table Construction:
    ""  a  b  c
""   0  0  0  0
a    0  1  1  1
b    0  1  2  2
c    0  1  2  3

Perfect match case:
All characters align perfectly
LCS = "abc", length = 3

Visual alignment:
String1: a b c
String2: a b c
LCS:     a b c
```
**Output:**
```
3
```

---

## 3. Edit Distance (Levenshtein)
A problem that teaches string transformation optimization and demonstrates multi-operation dynamic programming using minimum cost strategy for efficient text editing and optimal sequence conversion operations.

Given **two strings**, find the **minimum edit operations** (insert, delete, replace) to transform word1 into word2 using DP strategy. This operation is fundamental in **text processing** and **spell checking** where you need to **find minimum changes** for string transformation efficiently. The technique uses **2D DP** where each cell represents minimum operations to transform substring prefixes, considering three possible operations at each step. This concept is essential in **spell checkers**, **DNA analysis**, and **natural language processing** where measuring string similarity enables efficient correction systems and optimal transformation-based text analysis in editing applications.

This teaches **transformation DP** and **multi-operation optimization techniques** that are crucial for **string editing and efficient transformation cost minimization operations**.

**Your task:** Implement 2D dynamic programming to find minimum edit distance using insert, delete, and replace operations.

### Examples

**Input:**
```
Word1: "horse"
Word2: "ros"

2D DP Table Construction:
     ""  r  o  s
""    0  1  2  3  (insert r,o,s)
h     1  1  2  3  (replace h→r, then insert o,s)
o     2  2  1  2  (delete h, match o, insert s)
r     3  2  2  2  (delete h,o, match r, insert s)
s     4  3  3  2  (delete h,o, match r, match s)
e     5  4  4  3  (delete h,o,e, match r,s, insert s)

Operation trace back:
horse → rorse (replace h→r)
rorse → rose  (delete r)  
rose  → ros   (delete e)

Visual transformation:
horse
↓ replace h→r
rorse  
↓ delete o
rrose
↓ delete r  
rose
↓ delete e
ros

Total operations: 3
```
**Output:**
```
3
```

---

**Input:**
```
Word1: "intention"
Word2: "execution"

2D DP Table Construction:
         ""  e  x  e  c  u  t  i  o  n
    ""    0  1  2  3  4  5  6  7  8  9
    i     1  1  2  3  4  5  6  6  7  8
    n     2  2  2  3  4  5  6  7  7  7
    t     3  3  3  3  4  5  5  6  7  8
    e     4  3  4  3  4  5  6  6  7  8
    n     5  4  4  4  4  5  6  7  7  7
    t     6  5  5  5  5  5  5  6  7  8
    i     7  6  6  6  6  6  6  5  6  7
    o     8  7  7  7  7  7  7  6  5  6
    n     9  8  8  8  8  8  8  7  6  5

Minimum operations needed: 5
Transformation sequence involves multiple insert/delete/replace operations
```
**Output:**
```
5
```
