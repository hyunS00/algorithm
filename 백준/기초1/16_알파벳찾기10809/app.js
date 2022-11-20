const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = "";
let answer = "";
let abc = Array(26).fill(-1);

rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  for (let i = 0; i < input.length; i++) {
    if (abc[input.charCodeAt(i) - 97] === -1) {
      abc[input.charCodeAt(i) - 97] = i;
    }
  }
  answer = abc.join(" ");
  console.log(answer);
});
