const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = "";

rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  input = Number(input);
  let dp = Array(input + 1)
    .fill(0)
    .map((e, i) => i);
  for (let i = 1; i <= input; i++) {
    for (let j = 1; i + j * j <= input; j++) {
      if (dp[i + j * j] > dp[i] + 1 || dp[i + j * j] === 0)
        dp[i + j * j] = dp[i] + 1;
    }
  }
  console.log(dp);
});
