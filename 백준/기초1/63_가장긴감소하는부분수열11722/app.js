const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const N = input.splice(0, 1) * 1;
  input = input[0].split(" ");
  let dp = Array(N).fill(1);
  let max;
  for (let i = 1; i < N; i++) {
    max = 0;
    for (let j = i - 1; j >= 0; j--) {
      if (input[i] * 1 < input[j] * 1 && max < dp[j]) {
        max = dp[j];
      }
    }
    dp[i] = max + 1;
  }
  dp.sort((a, b) => b - a);
  console.log(dp[0]);
});
