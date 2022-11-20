const fs = require("fs");
const input = fs.readFileSync("./10866.txt").toString().split(`\r\n`);
let answer = "";
class Deqeue {
  constructor() {
    this.arr = [];
  }
  push_front(x) {
    //unshift 배열 맨앞에 추가하는 함수
    this.arr.unshift(x);
  }
  push_back(x) {
    //push 배열 앞에 추가하는 함수
    this.arr.push(x);
  }
  pop_front() {
    if (this.empty()) {
      return -1;
    } else {
      //shift 배열 앞에 빼는함수
      return this.arr.shift();
    }
  }
  pop_back() {
    if (this.empty()) {
      return -1;
    } else {
      //pop 배열 뒤에 빼는함수
      return this.arr.pop();
    }
  }
  size() {
    return this.arr.length;
  }
  empty() {
    if (this.arr.length === 0) {
      return 1;
    } else {
      return 0;
    }
  }
  front() {
    if (this.empty()) {
      return -1;
    } else {
      return this.arr[0];
    }
  }
  back() {
    if (this.empty()) {
      return -1;
    } else {
      return this.arr[this.arr.length - 1];
    }
  }
}

let dq = new Deqeue();
const N = input[0];
let instruction;
for (let i = 1; i <= N; i++) {
  // split(" ")공백을 기준으로 배열로 만듦
  instruction = input[i].split(" ");
  //스플릿으로 만든 배열이 2이상이면 push나 pop
  if (instruction.length >= 2) {
    dq[instruction[0]](Number(instruction[1]));
    //아니면 size,empty둥둥
  } else {
    console.log(`${dq[instruction[0]]()}`);
  }
}
