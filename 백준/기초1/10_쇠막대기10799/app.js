const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let answer = "";
let input = [];
let stackArr = [];
let head;
rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  let count = 0;
  for (let i = 0; i < input[0].length; i++) {
    head = input[0][i - 1];
    if (input[0][i] === "(") {
      stackArr.push("(");
    } else if (input[0][i] === ")") {
      stackArr.pop();
      if (head === "(") {
        count += stackArr.length;
      } else {
        count++;
      }
    }
  }
  answer = count;
  console.log(answer);
});
