
# April 21, 2023

# deque: doubly ended queue

from timeit import timeit
from collections import deque

class doubleQueue:
  def __init__(self):
    self._list=deque()

  def push(self, item):
    self._list.append(item)

  def pop(self):
    return self._list.popleft()

  def __len__(self):
    return len(self._list)


def test(count= 10, cls=doubleQueue):
  myTest = cls()
  print("here", count)
  for i in range(count):
    myTest.push(i)
    assert len(myTest) == i + 1

  for i in range(count):
    assert myTest.pop() == i
    assert len(myTest) == count - i - 1


if __name__ == '__main__':
  test()
  print(" time: {}".format(timeit('test()', 'from __main__ import test')))


