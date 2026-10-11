import threading
from collections import deque

class BoundedBlockingQueue(object):

    def __init__(self, capacity: int):
        self.q = deque()
        self.add = threading.Semaphore(capacity)  # free slots
        self.remove = threading.Semaphore(0)      # available items

    def enqueue(self, element: int) -> None:
        self.add.acquire()        # wait for a free slot
        self.q.append(element)
        self.remove.release()     # one more item available

    def dequeue(self) -> int:
        self.remove.acquire()     # wait for an item
        element = self.q.popleft()
        self.add.release()        # one more free slot
        return element

    def size(self) -> int:
        return len(self.q)