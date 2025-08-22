import heapq

class Median:
    def __init__(self):
        self.small = []  # Maximum heap (stores negative values so that the smallest negative becomes the highest positive)
        self.large = []  # Minimum heap

    def add_num(self, num):
        # Add to maximum heap
        heapq.heappush(self.small, -num)
        
        # Balance : largest in small should go to large
        heapq.heappush(self.large, -heapq.heappop(self.small))

        # Maintain size property
        if len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))
            
    def median(self):
        if len(self.small) > len(self.large):
            return -self.small[0]
        return (-self.small[0] + self.large[0]) / 2
    
try:
    stream = list(map(int, input("Enter the stream of integers : ").split()))
    median_stream = Median()
    medians = []
    for num in stream:
        median_stream.add_num(num)
        medians.append(median_stream.median())
    print(", ".join(map(str, medians)))
except:
    print("Invalid input. Please try with a valid input.")
