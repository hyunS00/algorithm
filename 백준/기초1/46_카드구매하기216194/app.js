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
  let testCase = [];
  input.forEach((e) => {
    testCase.push(Number(e));
  });
  let dp = Array(100001).fill([Array(3).fill(0)]);
  dp[1] = [1, 0, 0];
  dp[2] = [0, 1, 0];
  dp[3] = [1, 1, 1];
  let i;
  for (i = 4; i < 100001; i++) {
    dp[i] = [
      (dp[i - 1][1] + dp[i - 1][2]) % 1000000009,
      (dp[i - 2][0] + dp[i - 2][2]) % 1000000009,
      (dp[i - 3][0] + dp[i - 3][1]) % 1000000009,
    ];
  }
  testCase.forEach((e) => {
    answer += `${(dp[e][0] + dp[e][1] + dp[e][2]) % 1000000009}\n`;
  });
  console.log(answer);
});
