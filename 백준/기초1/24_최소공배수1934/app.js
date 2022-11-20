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
  const T = Number(input[0]);
  let A, B;
  let tmp;
  let i, j;
  let line;
  for (i = 1; i <= T; i++) {
    line = input[i].split(" ");
    A = Number(line[0]);
    B = Number(line[1]);
    if (A > B) {
      tmp = A;
      A = B;
      B = tmp;
    }
    tmp = 1;
    for (j = A; j > 1; j--) {
      if (A % j === 0 && B % j === 0) {
        A /= j;
        B /= j;
        tmp *= j;
      }
    }
    answer += `${tmp * A * B}\n`;
  }
  console.log(answer);
});
