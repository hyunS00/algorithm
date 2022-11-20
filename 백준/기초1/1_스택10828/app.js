const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().split("\r\n");

const N = parseInt(input[0]);
const inputCommand = input.slice(1, N + 1);
const arr = [];
let answer = "";
const stackCommand = {
  size: function size() {
    return arr.length;
  },
  empty: function empty() {
    if (this.size() <= 0) {
      return 1;
    } else {
      return 0;
    }
  },
  top: function top() {
    if (this.empty()) {
      return -1;
    } else {
      return arr[arr.length - 1];
    }
  },
  push: function push(num) {
    arr.push(num);
  },
  pop: function pop() {
    if (this.empty()) {
      return -1;
    } else {
      return arr.pop();
    }
  },
};

function solution(N, inputCommand) {
  let command = [];
  let funcCommand;
  let num;
  command = inputCommand[0].split(" ");
  for (let i = 0; i < N; i++) {
    command = inputCommand[i].split(" ");
    funcCommand = command[0];
    if (funcCommand === "push") {
      num = parseInt(command[1]);
      stackCommand[funcCommand](num);
    } else {
      answer += `${stackCommand[funcCommand]()}\n`;
    }
  }
  console.log(answer);
}

solution(N, inputCommand);
