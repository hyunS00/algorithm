const fs = require("fs");
const input = fs.readFileSync("./1158.txt").toString().split(` `);

const N = Number(input[0]);
const K = Number(input[1]);
let i;
let answer = "<";
let person = Array(N)
  .fill()
  .map((v, i) => {
    return i + 1;
  });
let tmp;
for (; person.length > 1; ) {
  console.log(person);
  for (i = 0; i < K - 1; i++) {
    tmp = person[0];
    person.shift();
    person.push(tmp);
  }

  answer += `${person.shift()}, `;
}

answer += `${person[0]}>`;
console.log(answer);
