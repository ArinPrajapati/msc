class ArrayQueue:
    def __init__(self):
        self.queue = []

    def push(self, x):
        self.queue.append(x)

    def pop(self):
        if(self.isEmpty()):
            return None
        value = self.queue.pop(0)

    def peek(self):
        if(self.isEmpty()):
            return None
        return self.queue[0]

    def isEmpty(self):
        return len(self.queue) == 0


