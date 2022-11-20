const fs = require('fs');
const input = fs.readFileSync('/dev/std').toString();
const N = parseInt(input);
for(let i=1; i<10; i++){
  console.log(`${N} * ${i} = ${N*i}`);
}