let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(" ");
let A = parseFloat(input[0]);
let B = parseFloat(input[1]);
console.log(A/B);