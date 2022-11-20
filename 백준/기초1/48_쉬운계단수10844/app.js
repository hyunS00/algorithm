const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let answer = 0;
rl.on("line", (line) => {
  input = Number(line);
}).on("close", () => {
  let dp = Array(input + 1).fill(Array(10).fill(0));
  dp[1] = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1];
  for (let i = 2; i <= input; i++) {
    dp[i] = [
      dp[i - 1][1] % 1000000000,
      (dp[i - 1][0] + dp[i - 1][2]) % 1000000000,
      (dp[i - 1][1] + dp[i - 1][3]) % 1000000000,
      (dp[i - 1][2] + dp[i - 1][4]) % 1000000000,
      (dp[i - 1][3] + dp[i - 1][5]) % 1000000000,
      (dp[i - 1][4] + dp[i - 1][6]) % 1000000000,
      (dp[i - 1][5] + dp[i - 1][7]) % 1000000000,
      (dp[i - 1][6] + dp[i - 1][8]) % 1000000000,
      (dp[i - 1][7] + dp[i - 1][9]) % 1000000000,
      dp[i - 1][8] % 1000000000,
    ];
  }
  for (let i = 0; i < 10; i++) {
    answer += dp[input][i];
  }
  console.log(answer % 1000000000);
});
