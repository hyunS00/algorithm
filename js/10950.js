
const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input = [];

rl.on('line', function (line) {
  input.push(line);
}).on('close', function () {
  const T = parseInt(input[0]);
  console.log()
  let testCase;
  let A ;
  let B ;
  for (let i=1; i<=T; i++){
    testCase = input[i].split(' ');
    A = parseInt(testCase[0]);
    B = parseInt(testCase[1]);
    console.log(A+B);
  }

process.exit();
});