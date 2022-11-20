const fs = require("fs");
const input = fs.readFileSync("./17299.txt").toString().split(`\n`);
let answer = "";
let N = Number(input[0]);
let freqArr = Array(1000001).fill(0);
let A = input[1].split(" ").map((e) => {
  freqArr[Number(e)]++;
  return Number(e);
});
let stackArr = [freqArr[A[N - 1]]];
let roopAble;
for (let i = N - 1; i >= 0; i--) {
  roopAble = true;
  while (roopAble) {
    if (freqArr[A[i]] >= freqArr[stackArr[stackArr.length - 1]]) {
      stackArr.pop();
    } else if (stackArr[0] === undefined) {
      answer = `-1 ${answer}`;
      stackArr.push(A[i]);
      roopAble = false;
    } else if (freqArr[A[i]] < freqArr[stackArr[stackArr.length - 1]]) {
      answer = `${stackArr[stackArr.length - 1]} ${answer}`;
      stackArr.push(A[i]);
      roopAble = false;
    }
  }
}
console.log(answer);
