const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
let answer = "";

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const A = Number(input.splice(0, 1));
  const testCase = input[0].split(" ");
  const Ai = testCase.map((e) => Number(e));
  Ai.unshift(0);
  let dp = Array(A + 1).fill(0);
  dp[1] = 1;
  let max;
  for (let i = 2; i <= A; i++) {
    max = 0;
    for (let j = i - 1; j >= 0; j--) {
      if (Ai[i] > Ai[j] && Ai[max] < Ai[j]) {
        max = j;
      }
    }
    if (max === 0) {
      dp[i] = dp[i - 1];
    } else {
      dp[i] = dp[max] + 1;
    }
  }
  answer = Math.max(...dp);
  console.log(answer);
});
