const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let answer = "";
let input = "";
rl.on("line", (line) => {
  input = line;
}).on("close", () => {});
