import threading

class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.index = 1
        self.condition = threading.Condition()

    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        with self.condition:
            while self.index <= self.n:
                if (self.index %3 == 0) and (self.index%5 !=0):
                    printFizz()
                    self.index += 1
                    self.condition.notify_all()
                else:
                    self.condition.wait()

    	

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        with self.condition:
            while self.index <= self.n:
                if (self.index %3 != 0) and (self.index%5 ==0):
                    printBuzz()
                    self.index += 1
                    self.condition.notify_all()
                else:
                    self.condition.wait()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        with self.condition:
            while self.index <= self.n:
                if (self.index %15 == 0):
                    printFizzBuzz()
                    self.index += 1
                    self.condition.notify_all()
                else:
                    self.condition.wait()

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        with self.condition:
            while self.index <= self.n:
                if (self.index %3 != 0) and (self.index%5 !=0):
                    printNumber(self.index)
                    self.index += 1
                    self.condition.notify_all()
                else:
                    self.condition.wait()
        