from collections import Counter, deque

def process_queue(queue, x):
    # Step 1: Remove all occurrences of x
    cleaned_queue = [item for item in queue if item != x]

    # Step 2: Check if all elements are unique
    is_unique = len(set(cleaned_queue)) == len(cleaned_queue)

    # Step 3: Count occurrences of each element
    frequency = dict(Counter(cleaned_queue))

    return {
        "cleaned_queue": cleaned_queue,
        "all_elements_unique": is_unique,
        "frequency_distribution": frequency
    }

# 🔍 Example Usage:
queue = [1, 2, 2, 3, 1, 4]
x = 2

result = process_queue(queue, x)

print("Cleaned Queue:", result["cleaned_queue"])
print("All Elements Unique:", result["all_elements_unique"])
print("Frequency Distribution:", result["frequency_distribution"])
