const { stdin, stdout } = require("process");
const readline = require("readline");
const rl = readline.createInterface({
  input: stdin,
  output: stdout,
});

let input = "";
let answer = "";
let abc = Array(26).fill(0);

rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  for (let i = 0; i < input.length; i++) {
    abc[input.charCodeAt(i) - 97]++;
  }
  answer = abc.join(" ");
  console.log(answer);
});
