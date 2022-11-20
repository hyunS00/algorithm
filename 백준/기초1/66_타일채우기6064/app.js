const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = "";

rl.on("line", (line) => {
  input = +line;
}).on("close", () => {
  if (input % 2 !== 0) {
    console.log(0);
    process.exit();
  }
  let dp = Array(input / 2).fill(1);

  for (let i = 1; i <= input / 2; i++) {
    dp[i] = dp[i - 1] * 3;
    for (let j = 1; j < i; j++) {
      console.log(i, j, dp);
      dp[i] += dp[i - j - 1] * 2;
    }
  }
  console.log(dp);
});
