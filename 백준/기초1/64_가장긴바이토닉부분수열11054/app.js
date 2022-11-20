const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const N = input.splice(0, 1) * 1;
  input = input[0].split(" ");
  let dp1 = Array(N).fill(1);
  let dp2 = Array(N).fill(1);
  let dp3 = Array(N).fill(1);
  let max;
  for (let i = 1; i < N; i++) {
    max = 0;
    for (let j = i - 1; j >= 0; j--) {
      if (input[i] * 1 > input[j] * 1 && max < dp1[j]) {
        max = dp1[j];
      }
    }
    dp1[i] = max + 1;
    max = 0;
    for (let j = N - i; j < N; j++) {
      if (input[N - i - 1] * 1 > input[j] * 1 && max < dp2[j]) {
        max = dp2[j];
      }
    }
    dp2[N - i - 1] = max + 1;
  }
  for (let i = 0; i < N; i++) {
    dp3[i] = dp1[i] + dp2[i] - 1;
  }
  dp3.sort((a, b) => b - a);
  console.log(dp3[0]);
});
