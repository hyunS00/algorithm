const fs = require("fs");
const input = fs.readFileSync("10845.txt").toString().split("\r\n");
/*
[
  '15',    'push 1', 'push 2',
  'front', 'back',   'size',
  'empty', 'pop',    'pop',
  'pop',   'size',   'empty',
  'pop',   'push 3', 'empty',
  'front'
]
*/
console.log(input);
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  push(x) {
    let node = new Node(x);
    if (this.size === 0) {
      this.head = node;
      this.tail = node;
    }
    this.tail.next = node;
    this.tail = node;
    this.size++;
  }

  pop() {
    if (!this.empty()) {
      let node = this.head;
      this.head = node.next;
      this.size--;
      return node.data;
    } else {
      return -1;
    }
  }

  empty() {
    if (this.size === 0) {
      return 1;
    } else {
      return 0;
    }
  }

  front() {
    if (!this.empty()) {
      return this.head.data;
    } else {
      return -1;
    }
  }

  back() {
    if (!this.empty()) {
      return this.tail.data;
    } else {
      return -1;
    }
  }
}

let answer = "";
const N = Number(input[0]);
let instruction;
let q = new Queue();

for (let i = 0; i < N; i++) {
  // push를 거르기위해사용
  // split 공백을 기준으로 배열로 만듦
  instruction = input[i + 1].split(" ");
  //배열로 만든 배열의 길이가 2이상이면 push
  if (instruction.length >= 2) {
    q[instruction[0]](Number(instruction[1]));
  } else if (instruction[0] === "pop") {
    console.log(q.pop());
  } else if (instruction[0] === "size") {
    console.log(q.size);
  } else if (instruction[0] === "empty") {
    console.log(q.empty());
  } else if (instruction[0] === "front") {
    console.log(q.front());
  } else if (instruction[0] === "back") {
    console.log(q.back());
  }
}

console.log(q);
