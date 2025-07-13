# Add two numbers represented as linked lists while handling carry propagation and leading zero elimination.
num1 = list(map(int, input("Enter digits of num1 (least significant first): ").split()))
num2 = list(map(int, input("Enter digits of num2 (least significant first): ").split()))

max_len = max(len(num1), len(num2))
while len(num1) < max_len:
    num1.append(0)
while len(num2) < max_len:
    num2.append(0)

carry = 0
result = []
for d1, d2 in zip(num1, num2):
    total = d1 + d2 + carry
    result.append(total % 10)
    carry = total // 10

if carry:
    result.append(carry)

print(" -> ".join(map(str, result)))
