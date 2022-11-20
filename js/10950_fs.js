const fs = require('fs');
const input = fs.readFileSync('10950.txt').toString().split('\r\n');


const T = parseInt(input[0]);
let testCase;
let A ;
let B ;
for (let i=1; i<=T; i++){
  testCase = input[i].split(' ');
  A = parseInt(testCase[0]);
  B = parseInt(testCase[1]);
  console.log(A+B);
}