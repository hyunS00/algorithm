const fs = require("fs");
const input = fs.readFileSync("./17298.txt").toString().split(`\r\n`);
const N = Number(input[0]);
let A = input[1].split(" ");
let answer = "";
let B = A.map((v) => Number(v));
let stackArr = [];
let roopAble = true;
for (let i = N - 1; i >= 0; i--) {
  while (roopAble) {
    if (B[i] >= stackArr[stackArr.length - 1]) {
      stackArr.pop();
    } else if (B[i] < stackArr[stackArr.length - 1]) {
      answer = `${stackArr[stackArr.length - 1]} ${answer}`;
      roopAble = false;
    } else if (stackArr[0] === undefined) {
      answer = `${-1} ${answer}`;
      roopAble = false;
    }
  }
  roopAble = true;
  stackArr.push(B[i]);
}

console.log(answer);
