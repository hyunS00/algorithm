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
  const n = Number(input.splice(0, 1));
  input.forEach((e, i) => {
    input[i] = e.split(" ");
  });
  for (let i = n - 2; i >= 0; i--) {
    for (let j = 0; j <= i; j++) {
      input[i][j] = Math.max(
        +input[i][j] + +input[i + 1][j],
        +input[i][j] + +input[i + 1][j + 1]
      );
    }
  }
  console.log(input[0][0]);
});
