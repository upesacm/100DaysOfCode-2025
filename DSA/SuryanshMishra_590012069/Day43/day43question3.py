# 3. Check if a Queue is Palindrome
# A problem that teaches symmetry detection algorithms and demonstrates combined queue-stack operations for sequence analysis using complementary data structure properties for pattern recognition.

# Given a queue of characters, determine whether the sequence forms a palindrome using only queue and stack operations. This operation requires understanding symmetry analysis where you need to compare sequence elements from both ends using the complementary properties of FIFO and LIFO structures. The technique is fundamental in pattern recognition and string analysis where you need to detect symmetric properties efficiently. Understanding this concept is crucial for data validation, sequence verification, and structural analysis where palindrome detection indicates special mathematical or linguistic properties.

# This teaches symmetry detection algorithms and dual data structure techniques that are essential for pattern recognition and efficient sequence symmetry analysis operations.

# Your task: Use complementary queue and stack operations to systematically compare sequence elements for palindrome detection through structural symmetry analysis.

# Examples
# Input:

# ['r', 'a', 'c', 'e', 'c', 'a', 'r']
# Output:

# Yes
# Input:

# ['a', 'b', 'c']
# Output: No

from collections import deque

def isPalindrome(queue):
    stack = []
    original_queue = deque(queue)  
    for ch in original_queue:
        stack.append(ch)

    for ch in original_queue:
        if ch != stack.pop():
            return "No"
    
    return "Yes"