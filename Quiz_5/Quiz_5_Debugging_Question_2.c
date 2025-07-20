Tasks: 

1. Identify the specific line(s) causing the bug:

2. Why this causes incorrect behavior:




task1 
if (n & (n - 1)) == 0:


task2
This logic works for positive powers of two.

But it incorrectly returns True for negative numbers that are not powers of two.
Example:

n = -8 (in two's complement binary) passes the check:

-8 & (-8 - 1) = 0

The function will wrongly return True, but -8 is not a power of two.

It also fails logically because:

Powers of two are positive integers only.
