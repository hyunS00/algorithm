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
  let testCase = input.map((e) => Number(e));
  let dp = Array(10 + 1).fill(Array(3).fill(0));
  dp[1] = [1, 0, 0];
  dp[2] = [1, 1, 0];
  dp[3] = [1, 1, 1];
  for (let i = 4; i <= 10; i++) {
    for (let j = 1; j <= i / 2; j++) {
      console.log(dp[i]);
      dp[i][0] += (dp[j][0] + dp[i - j][0]) % 1000000009;
      dp[i][1] += (dp[j][1] + dp[i - j][1]) % 1000000009;
      dp[i][2] += (dp[j][2] + dp[i - j][2]) % 1000000009;
    }
  }
  testCase.forEach((e) => {
    answer += `${(dp[e][0] + dp[e][1] + dp[e][2]) % 1000000009}\n`;
  });
  console.log(answer, dp);
});
