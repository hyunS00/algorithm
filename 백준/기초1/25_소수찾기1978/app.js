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
  const N = Number(input[0]);
  let num = input[1].split(" ");
  let count = 0;
  let fillter = Array(11).fill(1);
  fillter[1] = 0;
  for (let i = 2; i <= 10; i++) {
    if (fillter[i] === 0) continue;
    for (let j = i; i * j <= 10; j++) {
      fillter[i * j] = 0;
    }
  }
  for (let i = 0; i < num.length; i++) {
    if (fillter[Number(num[i])]) count++;
  }
  answer = count;
  console.log(answer);
});
