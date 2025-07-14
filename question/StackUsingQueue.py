from collections import deque

class StackUsingQueue:
    def __init__(self):
        self.q = deque()

    def push(self, x):
        self.q.append(x)
        for _ in range(len(self.q) - 1):
            self.q.append(self.q.popleft())

    def pop(self):
        if self.isEmpty():
            print("Stack is empty")
            return None
        return self.q.popleft()

    def top(self):
        if self.isEmpty():
            print("Stack is empty")
            return None
        return self.q[0]

    def isEmpty(self):
        return len(self.q) == 0

