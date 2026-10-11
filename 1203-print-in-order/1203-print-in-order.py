import threading

class Foo:
    def __init__(self):
        self.cv1 = threading.Semaphore(0)
        self.cv2 = threading.Semaphore(0)
        pass


    def first(self, printFirst: 'Callable[[], None]') -> None:
        printFirst()
        self.cv1.release()


    def second(self, printSecond: 'Callable[[], None]') -> None:
        self.cv1.acquire()
        printSecond()
        self.cv2.release()


    def third(self, printThird: 'Callable[[], None]') -> None:
        self.cv2.acquire()
        printThird()