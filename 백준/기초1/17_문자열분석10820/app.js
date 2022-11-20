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
  let small, big, num, space;
  let i;
  input.forEach((line) => {
    small = big = num = space = 0;
    for (i = 0; i < line.length; i++) {
      if (line.charCodeAt(i) >= 97) {
        small++;
      } else if (line.charCodeAt(i) >= 65) {
        big++;
      } else if (line.charCodeAt(i) >= 48) {
        num++;
      } else {
        space++;
      }
    }
    answer += `${small} ${big} ${num} ${space}\n`;
  });
  console.log(answer);
});
