from collections import deque

def word_ladder(begin_word, end_word, word_list):
    word_set = set(word_list)  # faster lookups

    # If end word is not present in the wordlist, no transformation is possible
    if end_word not in word_list:
        return 0
    
    queue = deque([(begin_word, 1)])  # (current_word, steps)

    while queue:
        word, steps = queue.popleft()

        if word == end_word:
            return steps
        
        # Try changing each letter
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                new_word = word[:i] + c + word[i + 1:]
                if new_word in word_set:
                    queue.append((new_word, steps + 1))
                    word_set.remove(new_word)   # avoid revisiting

    return 0

try:
    begin_word = input("Enter the begin word : ")
    end_word = input("Enter the end word : ")
    vertices = int(input("Enter the number of vertices : "))
    word_list = []

    print("Enter the words in the dictionary : ")
    for _ in range(vertices):
        word_list.append(input().strip())

    print(word_ladder(begin_word, end_word, word_list))
except:
    print("Invalid input. Please try with a valid input.")
