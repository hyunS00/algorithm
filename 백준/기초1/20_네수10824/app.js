const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let input = [];
rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  input = input.split(" ");
  let A = Number(input[0] + input[1]);
  let B = Number(input[2] + input[3]);
  console.log(A + B);
});
