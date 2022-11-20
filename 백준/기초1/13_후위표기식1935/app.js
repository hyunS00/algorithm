const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let answer = "";
let input = [];
let operator = [];
let stackArr = [];
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  let i = 0;
  const N = Number(input[0]);
  let askiNum;
  let A, B;
  for (i = 0; i < N; i++) {
    operator.push(Number(input[i + 2]));
  }
  for (i = 0; i < input[1].length; i++) {
    askiNum = input[1].charCodeAt([i]);
    if (askiNum >= 65) {
      stackArr.push(operator[askiNum - 65]);
    } else {
      B = stackArr.pop();
      A = stackArr.pop();
      if (askiNum === 42) {
        stackArr.push(A * B);
      } else if (askiNum === 43) {
        stackArr.push(A + B);
      } else if (askiNum === 45) {
        stackArr.push(A - B);
      } else if (askiNum === 47) {
        stackArr.push((Math.floor((A / B) * 100) / 100).toFixed(2));
      }
    }
  }
  answer = stackArr.pop();
  console.log(answer);
});
