const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let answer = "";

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  input.sort((a, b) => a - b);
  let num = input.map((v) => +v);
  let sum = num.reduce((acc, cur) => acc + cur);
  console.log(sum);
});
