const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input = [];

rl.on('line', function (line) {
  input.push(line);
}).on('close', function () {
  let A = parseInt(input[0]);
  let B = input[1];
  let output3 = parseInt(B[2]);
  let output4 = parseInt(B[1]);
  let output5 = parseInt(B[0]);
  console.log(A*output3);
  console.log(A*output4);
  console.log(A*output5);
  console.log(A*parseInt(B));

process.exit();
});