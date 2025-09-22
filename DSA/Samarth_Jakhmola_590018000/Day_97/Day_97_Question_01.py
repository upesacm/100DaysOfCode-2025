def minimum_palindrome_cuts(string):
    n = len(string)

    # Step 1 : Palindrome table initialization
    is_palindrome = [[False] * n for _ in range(n)]

    for i in range(n):
        is_palindrome[i][i] = True  # single character palindrome

    for length in range(2, n + 1):  # substring lengths
        for i in range(n - length + 1):
            j = i + length - 1
            if string[i] == string[j]:
                if length == 2:  # two characters
                    is_palindrome[i][j] = True
                else:
                    is_palindrome[i][j] = is_palindrome[i + 1][j - 1]

    # Step 2 : Cuts array
    cuts = [0] * n
    for i in range(n):
        if is_palindrome[0][i]:
            cuts[i] = 0
        else:
            cuts[i] = min(cuts[j] + 1 for j in range(i) if is_palindrome[j + 1][i])

    return cuts[n - 1]

string = input("Enter the string : ")
print(minimum_palindrome_cuts(string))
