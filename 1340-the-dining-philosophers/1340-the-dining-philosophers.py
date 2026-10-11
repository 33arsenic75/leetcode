from threading import Lock
from typing import Callable

class DiningPhilosophers:
    def __init__(self):
        self.forks = [Lock() for _ in range(5)]

    def wantsToEat(self, philosopher: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        right = philosopher
        left = (philosopher + 1) % 5
        first, second = min(left, right), max(left, right)

        with self.forks[first]:
            with self.forks[second]:
                pickLeftFork()
                pickRightFork()
                eat()
                putLeftFork()
                putRightFork()