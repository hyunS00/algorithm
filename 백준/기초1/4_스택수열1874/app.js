const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class Stack {
  constructor() {
    this.head = null;
    this.size = 0;
  }

  isEmpty() {
    return this.head === null ? 1 : 0;
  }

  getSize() {
    return this.size;
  }

  top() {
    return this.head.data;
  }

  push(data) {
    let node = new Node(data);
    node.next = this.head;
    this.head = node;
    this.size++;
  }

  pop() {
    let node = this.head;
    node.next = this.head.next;
    this.head = node.next;
    this.size--;
    return node.data;
  }
  isNext() {
    return this.head.next.data;
  }
}

let input = [];
let answer = "";
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  let n = input[0];
  let sequence = input.splice(1, 8);
  let num;
  let s = new Stack();
  for (let i = 0; i < n; i++) {
    num = +sequence[i];
    s.push(i + 1);
    while (num <= s.top()) {
      if (s.top() === num) {
        console.log(i, s.pop());
      }
    }
  }
  console.log(s);
});
