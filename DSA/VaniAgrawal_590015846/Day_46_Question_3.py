# Implement systematic queue merging using sequential append operations to create unified data structures while maintaining element ordering and queue efficiency.
q1_input = input("Enter elements of Queue 1 separated by spaces: ")
q1 = list(map(int, q1_input.split()))

q2_input = input("Enter elements of Queue 2 separated by spaces: ")
q2 = list(map(int, q2_input.split()))

merged_queue = q1 + q2

print("Merged Queue:", merged_queue)
