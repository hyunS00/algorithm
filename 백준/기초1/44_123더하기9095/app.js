const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let answer = "";

rl.on("line", (line) => {
  input.push(Number(line));
}).on("close", () => {
  const T = input.splice(0, 1);
  let dp = Array(12).fill(0);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (let i = 4; i <= 11; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }
  input.forEach((e) => {
    answer += `${dp[e]}\n`;
  });
  console.log(answer);
});
