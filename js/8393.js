const fs = require('fs');
const input = fs.readFileSync('8393.txt').toString();
const n = parseInt(input);
let sum = 0;
for(let i=1; i <=n; i++){
  sum += i;
}
console.log(sum);