const fs = require("fs");
const input = fs.readFileSync("1406.txt").toString().split("\r\n");

const M = parseInt(input[1]);
let instruction;
let cursor = input[0].length;
const str = input[0].split("");
let answer;
for (let i = 0; i < M; i++) {
  instruction = input[i + 2];
  if (instruction[0] === "P") {
    if (cursor > str.length) {
      cursor = str.length;
    }
    str.splice(cursor, 0, instruction[2]);
    cursor++;
  } else if (instruction[0] === "L") {
    cursor--;
    if (cursor < 0) {
      cursor = 0;
    }
  } else if (instruction[0] === "D") {
    cursor++;
    if (cursor > str.length) {
      cursor = str.length;
    }
  } else {
    cursor--;

    if (cursor < 0) {
      cursor = 0;
      continue;
    } else {
      str.splice(cursor, 1);
    }
  }
}
answer = str.join("");
console.log(answer);
