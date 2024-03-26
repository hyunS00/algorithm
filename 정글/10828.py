import sys

class Stack:
    def __init__(self):
        self.arr = []

    def size(self):
        return len(self.arr)
    
    def empty(self):
        return int(self.size() <= 0)
    
    def push(self,value):
        self.arr.append(value)
    
    def pop(self):
        if self.empty():
            return -1
        
        return self.arr.pop()
    
    def top(self):
        if self.empty():
            return -1
        return self.arr[self.size()-1]
    
N = int(input())

command_list = list(sys.stdin.readline().split() for i in range(N))

print(command_list)

stack = Stack()
for command in command_list:
    com = command[0]

    if com == 'push':
        stack.push(int(command[1]))
    elif com == 'pop':
        print(stack.pop())
    elif com == 'size':
        print(stack.size())
    elif com == 'empty':
        print(stack.empty())
    elif com == 'top':
        print(stack.top())