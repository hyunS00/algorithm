const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let answer = "";
let input = "";
rl.on("line", (line) => {
  input = line;
}).on("close", () => {
  for (let i = 0; i < input.length; i++) {
    if (input[i] === " ") {
      answer += " ";
    } else if (input.charCodeAt(i) >= 65 && input.charCodeAt(i) <= 90) {
      if (input.charCodeAt(i) + 13 >= 91) {
        answer += `${String.fromCharCode(input.charCodeAt(i) + 13 - 26)}`;
      } else {
        answer += `${String.fromCharCode(input.charCodeAt(i) + 13)}`;
      }
    } else if (input.charCodeAt(i) >= 97) {
      if (input.charCodeAt(i) + 13 >= 123) {
        answer += `${String.fromCharCode(input.charCodeAt(i) + 13 - 26)}`;
      } else {
        answer += `${String.fromCharCode(input.charCodeAt(i) + 13)}`;
      }
    } else {
      answer += `${input[i]}`;
    }
  }
  console.log(answer);
});
