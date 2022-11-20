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
  let arr = [];
  const N = input.length;
  for (let i = 0; i < N; i++) {
    arr[i] = input.slice(i, N);
  }
  arr.sort();
  console.log(arr.join("\n"));
});
