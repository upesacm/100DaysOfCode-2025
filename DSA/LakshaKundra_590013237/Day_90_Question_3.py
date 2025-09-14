from collections import deque

def word_ladder(begin, end, word_list):
    word_set = set(word_list)
    if end not in word_set:
        return 0
    q = deque([(begin,1)])
    while q:
        word, length = q.popleft()
        if word == end:
            return length
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                next_word = word[:i] + c + word[i+1:]
                if next_word in word_set:
                    word_set.remove(next_word)
                    q.append((next_word, length+1))
    return 0

begin = "hit"
end = "cog"
word_list = ["hot","dot","dog","lot","log","cog"]
print(word_ladder(begin, end, word_list))

begin = "hit"
end = "cog"
word_list = ["hot","dot","dog","lot","log"]
print(word_ladder(begin, end, word_list))
