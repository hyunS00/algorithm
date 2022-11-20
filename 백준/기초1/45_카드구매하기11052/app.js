const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let answers = "";

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const T = Number(input.splice(0, 1));
  input = input[0].split(" ");
  let dp = input.map((e) => Number(e));
  dp.unshift(0);
  for (let i = 2; i <= T; i++) {
    for (let j = 1; j <= i / 2; j++) {
      if (dp[i] < dp[j] + dp[i - j]) dp[i] = dp[j] + dp[i - j];
    }
  }
  console.log(dp[T]);
});
