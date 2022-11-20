const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const n = Number(input.splice(0, 1));
  input = input[0].split(" ");
  let arr = [];
  arr = input.map((e) => Number(e));
  let max = arr[0];
  for (let i = 1; i <= n; i++) {
    arr[i] = Math.max(arr[i], arr[i - 1] + arr[i]);
    max = Math.max(arr[i], max);
  }
  console.log(max);
});
