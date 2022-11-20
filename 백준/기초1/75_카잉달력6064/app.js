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
  const T = +input.splice(0, 1);
  let testCase;
  let N, M, x, y, k;
  let a, b;
  for (let i = 0; i < T; i++) {
    testCase = input[i].split(" ");
    M = testCase[0] * 1;
    N = testCase[1] * 1;
    x = testCase[2] * 1;
    y = testCase[3] * 1;
    k = 0;
    a = 0;
    b = 0;
    console.log(M, N, x, y, "시작");
    while (k <= 40000) {
      k++;
      a++;
      b++;
      if (a >= M) {
        a = 1;
      }
      if (b >= N) {
        b = 1;
      }
      console.log(k, a, b);
      if (a === x && b === y) {
        answer += `${k}\n`;
        break;
      }
    }
  }
  console.log(answer);
});
