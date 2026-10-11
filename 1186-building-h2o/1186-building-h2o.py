import threading

class H2O:
    def __init__(self):
        self.h = threading.Semaphore(2)
        self.o = threading.Semaphore(0)
        self.lock = threading.Lock()
        pass


    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        self.h.acquire()
        releaseHydrogen()
        self.o.release()

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        with self.lock:
            self.o.acquire()
            self.o.acquire()
            releaseOxygen()
            self.h.release()
            self.h.release()