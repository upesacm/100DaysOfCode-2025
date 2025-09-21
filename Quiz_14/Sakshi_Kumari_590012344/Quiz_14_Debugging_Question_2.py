1. Identify the indexing bug in array access 
Used weights[i] and values[i] instead of weights[i-1] and values[i-1].

2. Explain what happens when the function tries to access out-of-bounds indices.
When i = n, the function tries to access weights[n] and values[n], which don’t exist. 
This leads to an IndexError or incorrect results.

3. What should be the correct indexing for weights and values arrays?
Use weights[i-1] and values[i-1] because the DP table has an extra row for base cases, making item i correspond to index i-1 in the arrays.

