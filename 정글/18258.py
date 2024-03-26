import sys
from collections import deque

class Queue:
    def __init__(self):
        self.queue = deque()
    
    def size(self):
        return len(self.queue)
    
    def empty(self):
        return int(self.size() <= 0)
    
    def push(self,value):
        self.queue.append(value)

    def pop(self):
        if self.empty():
            return -1

        return self.queue.popleft()
    
    def front(self):
        if self.empty():
            return -1
        
        return self.queue[0]
    
    def back(self):
        if self.empty():
            return -1
        
        return self.queue[self.size()-1]
    
N = int(input())

command_list = list(sys.stdin.readline().split() for i in range(N))

queue = Queue()

for command in command_list:
    com = command[0]

    if com == 'push':
        queue.push(command[1])
    elif com == 'pop':
        print(queue.pop())
    elif com == 'size':
        print(queue.size())
    elif com == 'empty':
        print(queue.empty())
    elif com == 'front':
        print(queue.front())
    elif com == 'back':
        print(queue.back())