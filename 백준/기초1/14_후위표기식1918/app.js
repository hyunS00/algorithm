const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let answer = "";
let input = "";
rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  console.log(input);
  let stackArr = [];
  let priority = {
    "-": 1,
    "+": 1,
    "/": 2,
    "*": 2,
    "(": 3,
    ")": 3,
  };
  let head = 0;
  let top;
  for (let i = 0; i < input.length; i++) {
    console.log(i, stackArr, priority[input[i]], answer);
    if (input.charCodeAt(i) >= 65) {
      answer += `${input[i]}`;
    } else if (!stackArr && priority(input[i]) <= priority(head)) {
      answer += `${stackArr.pop()}`;
    } else if (input[i] === "(") {
      stackArr.push(input[i]);
    } else if (input[i] === ")") {
      top = stackArr[stackArr.length - 1];
      while (top !== "(") {
        answer += `${top}`;
        top = stackArr.pop();
      }
    } else {
      stackArr.push(input[i]);
    }
  }
  while (stackArr) {
    answer += `${stackArr.pop()}`;
  }
  console.log(answer);
});
