n = int(input("Enter a number: "))  # Taking input from user
l = n.bit_length() - 1
r = 0
while l > r:
    if ((n >> l) & 1) != ((n >> r) & 1):
        print(False)
        break
    l -= 1
    r += 1
else:
    print(True)
# For example
# input: 9
# output: True