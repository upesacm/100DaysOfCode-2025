from queue import Queue

def display_queue(q):
    """Display all elements from front to rear without modifying the queue."""
    size = q.qsize()
    for _ in range(size):
        element = q.get()
        print(element, end=' ')
        q.put(element)  # Re-enqueue to preserve original order
    print()

def get_queue_size(q):
    """Return the size of the queue."""
    return q.qsize()

def is_queue_empty(q):
    """Check if the queue is empty."""
    return q.empty()

# Example usage
if __name__ == "__main__":
    q = Queue()

    # Enqueue some elements
    q.put(10)
    q.put(20)
    q.put(30)

    print("Queue elements:")
    display_queue(q)

    print("Size of the queue:", get_queue_size(q))
    print("Is queue empty?", is_queue_empty(q))

    # Test with an empty queue
    empty_q = Queue()
    print("\nTesting with empty queue:")
    print("Is queue empty?", is_queue_empty(empty_q))
