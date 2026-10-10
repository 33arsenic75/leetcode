import threading

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.index = 0
        self.condition = threading.Condition()

	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        with self.condition:
            while self.index < 2*self.n:
                if self.index % 2 == 0:
                    printNumber(0)
                    self.index += 1
                    self.condition.notify_all()
                else:
                    self.condition.wait()
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        with self.condition:
            while self.index < 2*self.n:
                number = (self.index + 1)//2
                if (self.index % 2 == 1) and (number%2 == 0):
                    printNumber(number)
                    self.index += 1
                    self.condition.notify_all()
                else:
                    self.condition.wait()
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        with self.condition:
            while self.index < 2*self.n:
                number = (self.index + 1)//2
                if (self.index % 2 == 1) and (number%2 != 0):
                    printNumber(number)
                    self.index += 1
                    self.condition.notify_all()
                else:
                    self.condition.wait()
        
        