# Your task: Implement BFS-based word ladder to find shortest transformation sequence from begin word to end word using single-character changes.
from collections import deque

def word_ladder():
    begin_word = input("Enter the begin word: ")
    end_word = input("Enter the end word: ")
    word_list_str = input("Enter the word list as a list of strings, e.g., ['hot','dot','dog','lot','log','cog']: ")
    word_list = eval(word_list_str)
    
    word_set = set(word_list)
    if end_word not in word_set:
        print("Output: 0")
        return
    
    queue = deque([(begin_word, 1)])
    visited = {begin_word}
    
    while queue:
        word, length = queue.popleft()
        
        if word == end_word:
            print("Output:", length)
            return

        for i in range(len(word)):
            for char_code in range(ord('a'), ord('z') + 1):
                new_char = chr(char_code)
                new_word = word[:i] + new_char + word[i+1:]

                if new_word in word_set and new_word not in visited:
                    visited.add(new_word)
                    queue.append((new_word, length + 1))
    
    print("Output: 0")

word_ladder()
