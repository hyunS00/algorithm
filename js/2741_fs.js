const fs = require('fs');
const input = fs.readFileSync('2739.txt').toString();
const N = parseInt(input);
let answer='';
for(let i=N;i>0;i--){
  answer += i + '\n';
}
console.log(answer);