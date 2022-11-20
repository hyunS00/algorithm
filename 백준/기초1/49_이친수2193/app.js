const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = "";

rl.on("line", (line) => {
  input = Number(line);
}).on("close", () => {
  let dp = Array(input + 1).fill(Array(2).fill(0));
  dp[1] = [0, 1];
  dp[2] = [1, 0];
  for (let i = 3; i <= input; i++) {
    dp[i] = [BigInt(dp[i - 1][0]) + BigInt(dp[i - 1][1]), dp[i - 1][0]];
  }
  console.log((BigInt(dp[input][0]) + BigInt(dp[input][1])).toString());
});
