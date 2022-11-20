let fs = require('fs')
let input = fs.readFileSync('10869.txt').toString().split(' ');
let A = parseInt(input[0]);
let B = parseInt(input[1]);
console.log(A+B);
console.log(A-B);
console.log(A*B);
console.log(Math.floor(A/B));
console.log(A%B);
