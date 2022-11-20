const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const N = Number(input.splice(0, 1));
  input = input[0].split(" ");
  const A = input.map((e) => +e);
  let dp = A.map((e) => e);
  let i, j;
  let max, maxIndex;
  for (i = 1; i < N; i++) {
    max = 0;
    maxIndex = -1;
    for (j = i - 1; j >= 0; j--) {
      if (A[i] > A[j] && max < dp[j]) {
        max = dp[j];
        maxIndex = j;
      }
    }
    if (maxIndex !== -1) {
      dp[i] = dp[maxIndex] + A[i];
    }
  }
  dp.sort((a, b) => b - a);
  console.log(dp[0]);
});
