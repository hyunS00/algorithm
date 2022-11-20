const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = "";

rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  input = input.split(" ");
  a = parseInt(input[0]) - 1;
  b = parseInt(input[1]) - 1;
  c = parseInt(input[2]) - 1;
  let year = 0;

  while (true) {
    if (year % 15 === a && year % 28 === b && year % 19 === c) {
      break;
    }
    year++;
  }
  console.log(year + 1);
});
