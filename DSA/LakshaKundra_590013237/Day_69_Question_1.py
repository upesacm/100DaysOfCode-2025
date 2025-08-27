from collections import Counter

def canFormPalindrome(s):
    c=Counter(s)
    odd=sum(v%2 for v in c.values())
    return "Yes" if odd<=1 else "No"

print(canFormPalindrome("civic"))
print(canFormPalindrome("aabbcc"))
print(canFormPalindrome("abc"))
