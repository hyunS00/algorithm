const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = "";
let answer = "";

rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  let str = input.split(" ");
  let A = Number(str[0]);
  let B = Number(str[1]);
  let tmp;
  if (A > B) {
    tmp = A;
    A = B;
    B = tmp;
  }
  tmp = 1;
  for (let i = A; i > 1; i--) {
    if (A % i === 0 && B % i === 0) {
      A /= i;
      B /= i;
      tmp *= i;
    }
  }
  answer += `${tmp}\n${tmp * A * B}`;
  console.log(answer);
});
