# A basic queue
Numbers_to_add = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Queue = []


class Queue:
    def __init__(self):
        self.queue = []

    def add(self, number):
        if not isinstance(number, int):
            raise "Input is not a number"
        self.queue.append(number)

    def remove(self):
        self.queue = self.queue[1:]


MyQueue = Queue()
for number in Numbers_to_add:
    MyQueue.add(number)
    print(f"{number} is added to the queue.")

print(MyQueue.queue)
for number in MyQueue.queue:
    MyQueue.remove()
    print(f"{number} is removed from the queue.")