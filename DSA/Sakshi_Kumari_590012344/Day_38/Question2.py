class MyStack:
    def __init__(self):
        self.data = []
        self.min_data = []

    def push(self, number):
        self.data.append(number)
        if not self.min_data:
            self.min_data.append(number)
        else:
            current_min = self.min_data[-1]
            self.min_data.append(min(number, current_min))

    def pop(self):
        if self.data:
            self.data.pop()
            self.min_data.pop()

    def top(self):
        if self.data:
            return self.data[-1]

    def get_min(self):
        if self.min_data:
            return self.min_data[-1]
