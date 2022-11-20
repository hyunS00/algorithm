let fs = require('fs')
let input = fs.readFileSync('uclid.txt').toString().split(' ');
let A=parseInt(input[0]);
let B=parseInt(input[1]);
console.log(A,B);
let C;
while(C!=0){
  C=A%B;
  A=B;
  B=C;
}
console.log(A);