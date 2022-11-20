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
  const T = Number(input.splice(0, 1));
  let n;
  let arr = [];
  for (let i = 0; i < T; i++) {
    n = Number(input.splice(0, 1));
    arr = input.splice(0, 2);
    arr.forEach((e, i) => (arr[i] = e.split(" ")));
    arr[0].unshift(0);
    arr[0].unshift(0);
    arr[1].unshift(0);
    arr[1].unshift(0);
    for (let j = 2; j < n + 2; j++) {
      arr[0][j] =
        arr[0][j] * 1 + Math.max(arr[1][j - 1] * 1, arr[1][j - 2] * 1);
      arr[1][j] =
        arr[1][j] * 1 + Math.max(arr[0][j - 1] * 1, arr[0][j - 2] * 1);
    }
    answer += `${Math.max(arr[0][n + 1], arr[1][n + 1])}\n`;
  }
  console.log(answer);
});
