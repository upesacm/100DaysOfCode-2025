from collections import deque

def generate_binary_numbers(n):
    queue = deque(["1"])
    result = []

    for _ in range(n):
        current = queue.popleft()
        result.append(current)
        queue.append(current + "0")
        queue.append(current + "1")

    return result

try:
    if __name__ == "__main__":
        n = int(input("Enter the value of n : "))
        binary_numbers = generate_binary_numbers(n)
        print("[" + ", ".join(f'"{num}"' for num in binary_numbers) + "]")
except:
    print("Invalid input. Please try with a valid input.")
