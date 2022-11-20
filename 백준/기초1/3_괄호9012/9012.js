const fs = require("fs");
const input = fs.readFileSync("2739.txt").toString();

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
  push(data) {
    let node = new Node(data);
    node.next = this.head;
    this.head = node;
    this.size++;
  }

  pop() {
    if (this.isEmpty()) return -1;
    let node = this.head;
    node.next = this.head.next;
    this.head = node.next;
    return node.data;
  }

  getSize() {
    return this.size;
  }

  isEmpty() {
    return this.head === null ? 1 : 0;
  }

  clear() {
    this.head = null;
    this.size = 0;
  }
}

let input = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  let T = +input[0];
  let testCase;
  let s = new Stack();
  let emptyPop;
  for (let i = 1; i <= T; i++) {
    emptyPop = 0;
    testCase = input[i];
    for (let j = 0; j < testCase.length; j++) {
      if (testCase[j] === "(") {
        s.push("(");
      } else if (testCase[j] === ")") {
        if (s.pop() === -1) {
          emptyPop = 1;
          break;
        }
      }
    }
    if (!s.isEmpty() || s.getSize > 0 || emptyPop) {
      console.log("NO");
    } else {
      console.log("YES");
    }
    s.clear();
  }
});
